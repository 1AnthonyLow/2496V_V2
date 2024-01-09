#include "robot.h"
#include "PID.h"
#include "util.h"
#include "main.h"
#include <math.h>
#include <vector>

void move(float lpwr, float rpwr) {
    left = lpwr;
    right = rpwr;
}

void moveTo(float target, int timeout) {
    const float kP = 3.4; // 3.4
    const float kI = 0.00001; //0.00001
    const float kD = 2.1; //2.1
    const float kJ = 3;

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

    while(true) {
        controller.print(0,0, "error: %f", error);

        heading = imu.get_heading();
        if (heading - initial > 180) headingError = heading - initial - 360; // Heading correction
        else headingError = heading - initial;
        correction = headingError*kJ;

        prevError = error;
        error = target - lf.get_position(); //P

        if (fabs(error) < 20) integral += error * 0.1;

        derivative = error - prevError; // D

        output = error*kP+integral*kI+derivative*kD; //PID
        //if (output > powerCap) output = powerCap;

        if (fabs(error) < 1) {
            x ++; // Increase x by 10
            if (x >= 10) { 
                break; 
            }
        }
        else x = 0;

        move(output - correction, output + correction);

        if(timer.getTime() > timeout){
            break;
        }

        if(controller.get_digital(DIGITAL_UP)) break;
        //if (timer.getTime() > duration) break;
    }
    move(0,0);
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

    while(true) {
        timer.startTime();

        if (heading - initial > 180) error = heading - initial - 360; // P
        else error = heading - initial;

        integral = integral + error; // I
        if (fabs(error) < 1) integral = 0;
        else if (integral > 50) integral = 50;

        derivative = error - prevError; // D

        output = error*kP+integral*kI+derivative*kD; //PID
        if (output > powerCap) output = powerCap;

        if (error < 1) x++;
        if (x >= 10) break;

        move(output, -output);

        if (!(printTimer % 5)) {
            controller.print(0, 0, "%f", heading);
        }
        printTimer += 1;

        if (timer.getTime() > duration) break;
    }
    move(0,0);
}

void arc(float radius, float theta, std::string dir) {
    float curr;
    float error;
    float ratio;
    float inner = 0;
    float outer = 0;
    float ito = 11.05;
    float arclen = radius*M_PI*theta/180;
    float target = arclen;
    float offradius = radius - ito;

    std::string left = "left";
    std::string right = "right";

    reset();
    
    while(true) {
        if(dir.find(left) != std::string::npos) {
            curr = rf.get_position();
            move(inner, outer);
        }
        else if(dir.find(right) != std::string::npos) {
            curr = lf.get_position();
            move(outer, inner);
        }
        error = target - curr;
        ratio = offradius/radius; // The ratio of radii is equivalent to the ratio of speeds to maintain the arc
        outer = error;
        inner = ratio*outer;
        
    }
}

float heading_init;
void absTurn(float abstarget, int timeout){
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

    turnKP = 1.1;
    turnKI = 0.04;
    turnKD = 5.2;

    PID absrotate(turnKP, turnKI, turnKD);
    absrotate.resetVars();
    float turn_start_pos = imu.get_heading();
    timer.startTime();

    while(true){
        position = fmod(imu.get_rotation() - heading_init, 360);
        voltage = absrotate.calc(abstarget, position, TURN_INTEGRAL_KICK, TURN_MAX_INTEGRAL);
        move(voltage,-voltage);

        if (!(printTimer % 5)) {
        controller.print(0,0, "%f", position);
        controller.print(1,0, "%f", abstarget);
        }
        printTimer += 1;
        
        if (std::abs(abstarget - position) <= 0.75){
        count++;
        }

        // if(count >= 10){
        //     break;
        // }

        if(timer.getTime() > timeout){
            break;
        }
        pros::delay(10);
    }
    move(0,0);
}