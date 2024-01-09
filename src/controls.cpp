#include "main.h"
#include "pros/misc.h"
#include "robot.h"
#include "chassis.h"
#include "autons.h"
//#include "util.h"
//#include <cmath>

bool vert_wings_state = false;
bool horz_wings_state = false;
bool hang_state = false;
bool side_hang_state = false;

int abs_sgn(double input){
    return input/std::abs(input);
}

void driver() {

    float rpwr, lpwr;
    float rAxis, lAxis; 

    lAxis = controller.get_analog(ANALOG_LEFT_Y);
    rAxis = controller.get_analog(ANALOG_RIGHT_Y);

    if(std::abs(rAxis) > 2){
        if(rAxis > 0){
            rpwr = pow(1.03,(rAxis+70))-8;
        }
        else{
            rpwr = -1*pow(1.03,(-1*rAxis+70))+8.4;
        }
    }
    else{
        rpwr = 0;
    }
   
    if(std::abs(lAxis) > 2){
        if(lAxis > 0){
            lpwr = pow(1.03,(lAxis+70))-8;
        }
        else{
            lpwr = -1*pow(1.03,(-1*lAxis+70))+8.4;
        }
    }
    else{
        lpwr = 0;
    }
    move(lpwr,rpwr);

    if(controller.get_digital(DIGITAL_L2)){
        intake.move(-127);
        if(controller.get_digital(DIGITAL_R2)){
            vert_wings.set_value(true);
        }
        else{
            vert_wings.set_value(false);
        }
    }
    else if(controller.get_digital(DIGITAL_L1)){
        intake.move(127);
        if(controller.get_digital(DIGITAL_R1)){
            horiz_wings.set_value(true);
        }
        else{
            horiz_wings.set_value(false);
        }
    }
    else{
        intake.move(0);
    }

    if(controller.get_digital_new_press(DIGITAL_B)){
        hang_state = !hang_state;
        bar_hang.set_value(hang_state);
    }

    if(controller.get_digital_new_press(DIGITAL_DOWN)){
        side_hang_state = !side_hang_state;
        side_hang.set_value(side_hang_state);
    }

    if(controller.get_digital(DIGITAL_LEFT)){
        moveTo(1000, 5000);
    }


    /*if(L2) intake.move(127);
    else if(L1) intake.move(-127);
    else intake.move(0); 
    done

    if(R2) slapper.move(127);
    else slapper.move(0);

    if(L1 and R1) horiz_wings.set_value(true);
    else horiz_wings.set_value(false);
    done

    if(L2 and R2) vert_wings.set_value(true);
    else horiz_wings.set_value(false);
    done

    if(B) bar_hang.set_value(true);
    else bar_hang.set_value(false);
    done

    if(DOWN) side_hang.set_value(false);
    else side_hang.set_value(true);
    done
    */
}