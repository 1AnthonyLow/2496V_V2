#include "robot.h"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::IMU imu(12);

pros::Motor lf(1, MOTOR_GEARSET_06, true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lm(4, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);
pros::Motor lb(5, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

pros::Motor rf(6, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rm(3, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor rb(2, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

pros::Motor_Group left({lf, lm, lb});
pros::Motor_Group right({rf, rm, rb});

pros::Motor slapper(20, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

pros::Motor intake(8, MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor mot_hang(19, MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut PTO('H', false);
pros::ADIDigitalOut side_hang('G', false);
pros::ADIDigitalOut vert_wings('C', false);
pros::ADIDigitalOut horiz_wings('F', false);