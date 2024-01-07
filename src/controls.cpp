#include "main.h"
#include "robot.h"
#include "chassis.h"
#include "autons.h"
//#include "util.h"
//#include <cmath>

void driver() {
    left = controller.get_analog(ANALOG_LEFT_Y);
    right = controller.get_analog(ANALOG_RIGHT_Y);

    /*if(L2) intake.move(127);
    else if(L1) intake.move(-127);
    else intake.move(0);

    if(R2) slapper.move(127);
    else slapper.move(0);

    if(L1 and R1) horiz_wings.set_value(true);
    else horiz_wings.set_value(false);

    if(L2 and R2) vert_wings.set_value(true);
    else horiz_wings.set_value(false);

    if(B) bar_hang.set_value(true);
    else bar_hang.set_value(false);

    if(DOWN) side_hang.set_value(false);
    else side_hang.set_value(true);
    */

    if(controller.get_digital_new_press(DIGITAL_LEFT)) test();
}