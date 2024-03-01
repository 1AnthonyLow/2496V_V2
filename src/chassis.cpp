#include "PID.h"
#include "display/lv_misc/lv_task.h"
#include "main.h"
#include "robot.h"
#include "util.h"
#include <cmath>
#include <math.h>
#include <vector>

void move(float lpwr, float rpwr) {
  left = lpwr;
  right = rpwr;
}

void moveTo(float target, int timeout) {
  const float kP = 3.4;     // 3.4
  const float kI = 0.00001; // 0.00001
  const float kD = 2.1;     // 2.1
  const float kJ = 7;

  float error = 0;
  float integral = 0;
  float derivative;
  float output;
  float correction;
  float prevError;
  float initial = imu.get_heading();
  float heading;
  float headingError;
  int x = 0;

  reset();

  Timer timer;
  timer.startTime();

  while (true) {
    controller.print(0, 0, "error: %f", error);

    heading = imu.get_heading();
    if (heading - initial > 180)
      headingError = heading - initial - 360; // Heading correction
    else
      headingError = heading - initial;
    correction = headingError * kJ;

    prevError = error;
    error = target - lf.get_position(); // P

    if (fabs(error) < 20)
      integral += error * 0.1;

    derivative = error - prevError; // D

    output = error * kP + integral * kI + derivative * kD; // PID
    // if (output > powerCap) output = powerCap;

    if (fabs(error) < 1) {
      x++; // Increase x by 10
      if (x >= 10) {
        break;
      }
    } else
      x = 0;

    move(output - correction, output + correction);

    if (timer.getTime() > timeout) {
      break;
    }

    if (controller.get_digital(DIGITAL_UP))
      break;
    // if (timer.getTime() > duration) break;
  }
  move(0, 0);
}

void turnTo(float target, int duration, int powerCap) {
  float kP = 2;
  float kI = 0;
  float kD = 0;

  float error = 0;
  float integral = 0;

  float derivative;
  float output;
  float prevError;
  float initial = imu.get_heading();
  float heading;

  int x = 0;
  int printTimer = 0;

  reset();

  Timer timer;

  while (true) {
    timer.startTime();

    if (heading - initial > 180)
      error = heading - initial - 360; // P
    else
      error = heading - initial;

    integral = integral + error; // I
    if (fabs(error) < 1)
      integral = 0;
    else if (integral > 50)
      integral = 50;

    derivative = error - prevError; // D

    output = error * kP + integral * kI + derivative * kD; // PID
    if (output > powerCap)
      output = powerCap;

    if (error < 1)
      x++;
    if (x >= 10)
      break;

    move(output, -output);

    if (!(printTimer % 5)) {
      controller.print(0, 0, "%f", heading);
    }
    printTimer += 1;

    if (timer.getTime() > duration)
      break;
  }
  move(0, 0);
}

void arcTurn(float leftPower, float rightPower, float duration) {
  left.move(leftPower);
  right.move(rightPower);
  pros::delay(duration);
  left.move(0);
  right.move(0);
}

void arc(float radius, float theta, std::string dir) {
  float curr;
  float error;
  float ratio;
  float inner = 0;
  float outer = 0;
  float ito = 11.05;
  float arclen = radius * M_PI * theta / 180;
  float target = arclen;
  float offradius = radius - ito;

  std::string left = "left";
  std::string right = "right";

  reset();

  while (true) {
    if (dir.find(left) != std::string::npos) {
      curr = rf.get_position();
      move(inner, outer);
    } else if (dir.find(right) != std::string::npos) {
      curr = lf.get_position();
      move(outer, inner);
    }
    error = target - curr;
    ratio = offradius / radius; // The ratio of radii is equivalent to the ratio
                                // of speeds to maintain the arc
    outer = error;
    inner = ratio * outer;
  }
}

float absKP(double turn_distance) {
  return (9.1353 * pow(10, -9)) * pow(turn_distance, 4) +
         (-0.00000445865) * pow(turn_distance, 3) +
         (0.000789503) * pow(turn_distance, 2) + (-0.0619252) * turn_distance +
         3.08139;
}

float absKD(double turn_distance) {
  return (-7.7559 * pow(10, -9)) * pow(turn_distance, 4) +
         (0.00000317886) * pow(turn_distance, 3) +
         (-0.000387428) * pow(turn_distance, 2) + (0.00817919) * turn_distance +
         5.8674;
}

float absKI(double turn_distance) {
  return (-3.7659 * pow(10, -9)) * pow(turn_distance, 4) +
         (0.00000169813) * pow(turn_distance, 3) +
         (-0.000257537) * pow(turn_distance, 2) +
         (0.0145666) * (turn_distance) + -0.190512;
}

float heading_init;
void absTurn(float abstarget, int timeout) {
  Timer timer;
  float voltage;
  float position;
  float turnKP;
  float turnKI;
  float turnKD;
  int count = 0;

  int printTimer = 0;
  float printPos = 0;
  controller.clear();

  if (std::abs(abstarget - imu.get_rotation()) <= 45) {
    turnKP = 1.48;
    turnKI = 0.004;
    turnKD = 6.2;
  } else if (std::abs(abstarget - imu.get_rotation()) <= 90) {
    turnKP = 1.31;
    turnKI = 0.01;
    turnKD = 6.7;
  } else if (std::abs(abstarget - imu.get_rotation()) <= 135) {
    turnKP = 1.07;
    turnKI = 0.0134;
    turnKD = 5.5;
  } else if (std::abs(abstarget - imu.get_heading()) <= 180) {
    turnKP = 0.91;
    turnKI = 0.006;
    turnKD = 3.6;
  }

  PID absrotate(turnKP, turnKI, turnKD); // turnKP, turnKI, turnKD
  absrotate.resetVars();
  float turn_start_pos = imu.get_heading();
  timer.startTime();

  while (true) {
    position = fmod(imu.get_rotation() - heading_init, 360);
    voltage = absrotate.calc(abstarget, position, TURN_INTEGRAL_KICK,
                             TURN_MAX_INTEGRAL);
    move(voltage, -voltage);

    if (!(printTimer % 5)) {
      controller.print(0, 0, "%f", position);
      controller.print(1, 0, "%f", abstarget);
    }
    printTimer += 1;

    if (std::abs(abstarget - position) <= 0.75) {
      count++;
    }

    if (count >= 10) {
      break;
    }

    if (timer.getTime() > timeout) {
      break;
    }
    pros::delay(10);
  }
  move(0, 0);
}

void moveTest(float target, int timeOut, float power_cap) {
  float encoder_average;
  float voltage;
  float currPos = 0;
  int printTimer = 0;
  float imuInit;
  float heading;
  int count = 0;

  float moveKp = 1.04;
  float moveKI = 0.05;
  float moveKD = 2.6;

  PID straight(moveKp, moveKI, moveKD);

  reset();
  controller.clear();
  straight.resetVars();
  imuInit = imu.get_rotation();

  Timer timer;
  while (true) {
    encoder_average = (lb.get_position() + rb.get_position()) / 2;

    heading = imuInit - imu.get_rotation();
    heading = heading * 6;

    currPos = target - encoder_average;
    if (!(printTimer % 5)) {
      controller.print(0, 0, "%f", currPos);
    }
    printTimer += 1;

    voltage = straight.calc(target, encoder_average, STRAIGHT_INTEGRAL_KICK,
                            STRAIGHT_MAX_INTEGRAL);

    if (std::abs(voltage) > power_cap) {
      voltage = power_cap * voltage / std::abs(voltage);
    }

    move(voltage + heading, voltage - heading);

    if (timer.getTime() > timeOut) {
      break;
    }
    if (std::abs(target - encoder_average) <= 0.8) {
      count++;
    }
    if (count >= 10) {
      break;
    }
    pros::delay(10);
  }
  move(0, 0);
}

void arcTurnRight(float radius, float theta, int timeout) {
  float kp = 0;
  float ki = 0;
  float kd = 0;

  double righttheta;
  float correction;

  float voltageRight; 
  float voltageLeft;

  Timer timer;
  int printTimer = 0;

  double pi = 3.14159265359;

  float imu_start = imu.get_heading();
  if (imu_start > 180) {
    imu_start -= 360;
  }

  int count = 0;

  controller.clear();
  PID arcTurnRight (kp, ki, kd);
  arcTurnRight.resetVars();

  double rightTarget = 0;
  double leftTarget = 0;

  rightTarget = double((theta / 180) * pi * radius);
  leftTarget = double((theta / 180)*pi * (radius + 209));

  while(true) {
    float heading = imu.get_heading() - imu_start;
    if( theta > 0){
      if(heading > 300){
        heading -= 360;
      }
    }
    else{
      if (heading > 30){
        heading -= 360;
      }
    }

    float positionRight = (rf.get_position() + rb.get_position()) / 2;
    float positionLeft = (lf.get_position() + lb.get_position()) / 2;

    voltageRight = arcTurnRight.calc(rightTarget, positionRight, STRAIGHT_INTEGRAL_KICK, STRAIGHT_MAX_INTEGRAL);
    voltageLeft = arcTurnRight.calc(leftTarget, positionLeft, STRAIGHT_INTEGRAL_KICK, STRAIGHT_MAX_INTEGRAL);

    if(std::abs(voltageLeft) > 100){
      voltageLeft = 100 * (voltageLeft / std::abs(voltageLeft));
    }

    if(std::abs(voltageRight) > 70){
      voltageRight = 70 * (voltageRight / std::abs(voltageRight));
    }

    righttheta = (positionRight * 180) / (pi * radius);
    correction = (heading = righttheta);
    correction = correction * 10;

    if(!(printTimer % 5)){
      controller.print(1,0, "%f", float(heading));
    }
    printTimer += 1;

    move(voltageLeft - correction, voltageRight + correction);

    if(timer.getTime() > timeout){
      break;
    }

    if ((abs(leftTarget - positionLeft) <= 4) && abs(rightTarget - positionRight) <= 4){
      count++;
    }

    if(count > 10){
      break;
    }

    pros::delay(10);
  }
  move(0,0);
}