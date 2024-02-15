#ifndef ROBOT_H_
#define ROBOT_H_

#include "main.h"
#include "pros/adi.hpp"

extern pros::Controller controller;

extern pros::Motor slapper;

extern pros::Motor lf;
extern pros::Motor lm;
extern pros::Motor lb;
extern pros::Motor rf;
extern pros::Motor rm;
extern pros::Motor rb;

extern pros::Motor_Group left;
extern pros::Motor_Group right;

extern pros::Motor intake;
extern pros::Motor mot_hang;

extern pros::ADIDigitalOut PTO;
extern pros::ADIDigitalOut side_hang;
extern pros::ADIDigitalOut vert_wings;
extern pros::ADIDigitalOut horiz_wings;

extern pros::Imu imu;

#endif