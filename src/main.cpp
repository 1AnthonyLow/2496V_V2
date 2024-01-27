#include "main.h"
#include "robot.h"
#include "controls.h"
#include "chassis.h"
#include "autons.h"

void on_center_button() {
	horiz_wings.set_value(true);
}

void initialize() {
	pros::lcd::initialize();
	imu.reset();
	bar_hang.set_value(false);
	side_hang.set_value(false);
	vert_wings.set_value(false);
	horiz_wings.set_value(false);
}

void disabled() { 
}

void competition_initialize() {}

void autonomous() {
	leftsideElims();
}

void opcontrol() {
	while (true) {
		driver();
		pros::delay(20);
	}
}
