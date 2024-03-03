#include "main.h"
#include "autons.h"
#include "chassis.h"
#include "controls.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.h"

void on_center_button() { horiz_wings.set_value(true); }

void initialize() {
  pros::lcd::initialize();
  imu.reset();
  bar_hang.set_value(false);
  side_hang.set_value(false);
  horiz_wings.set_value(false);
}

void disabled() {}

int selectedAuto = 0;
int timer = 0;

void competition_initialize() {
  // controller.clear();
  // while (true) {
  //   if (auton_selector.get_new_press()) {
  //     	selectedAuto += 1;
	// 	controller.clear();
  //   }
  //   if (selectedAuto > 5) {
  //     selectedAuto = 0;
  //   }

  //   if (!(timer % 5)) {
  //     switch (selectedAuto) {
  //     case 0:
  //       controller.print(1, 0, "No Auton");
  //       break;
  //     case 1:
  //       controller.print(1, 0, "Right Side Qual");
  //       break;
  //     case 2:
  //       controller.print(1, 0, "Left Side Qual");
  //       break;
  //     case 3:
  //       controller.print(1, 0, "Right Side Elims");
  //       break;
  //     case 4:
  //       controller.print(1, 0, "Left Side Elims");
	// 	break;
  //     case 5:
  //       controller.print(1, 0, "Skills");
  //       break;
  //     default:
  //       controller.print(1, 0, "Selection");
  //     }
  //   }
  //   pros::delay(10);
  //   timer++;
  // }
}

void autonomous() {
  // switch (selectedAuto) {
  // case 0:
  //   noAuton();
  //   break;
  // case 1:
  //   rightsideQual();
  //   break;
  // case 2:
  //   leftsideQual();
  //   break;
  // case 3:
  //   rightSideElims();
  //   break;
  // case 4:
  //   leftsideElims();
  //   break;
  // case 5:
  //   skills();
  //   break;
  // default:
  //   noAuton();
  // }
  rightsideQual();
}

void opcontrol() {
  while (true) {
    driver();
    pros::delay(20);
  }
}
