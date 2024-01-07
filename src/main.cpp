#include "main.h"
#include "robot.h"
#include "controls.h"

void on_center_button() {

}

void initialize() {
	pros::lcd::initialize();
	imu.reset();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (true) {
		driver();
		pros::delay(20);
	}
}
