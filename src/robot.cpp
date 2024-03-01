#include "robot.h"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::IMU imu(18);

pros::Motor lf(15, MOTOR_GEARSET_06, true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lm(16, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lb(17, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(4, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rm(5, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rb(6, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor_Group left({lf, lm, lb});
pros::Motor_Group right({rf, rm, rb});

pros::Motor slapper(3, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

pros::Motor intake(19, MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut bar_hang('F', false);
pros::ADIDigitalOut side_hang('A', false);
pros::ADIDigitalOut horiz_wings('H', false);
pros::ADIDigitalIn auton_selector('E');