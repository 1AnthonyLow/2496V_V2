#include "robot.h"
#include "main.h"

bool L1;
bool L2;
bool R1;
bool R2;
bool B;
bool DOWN;

class Timer {
    private:
        int t;
    public:
        Timer(){startTime();}   
        void startTime() {t = pros::millis();}
        int getTime() {return (pros::millis() - t);}
};

void states() {
    if(controller.get_digital_new_press(DIGITAL_L1)) L1 = true;
    else L1 = false;

    if(controller.get_digital_new_press(DIGITAL_L2)) L2 = true;
    else L2 = false;

    if(controller.get_digital_new_press(DIGITAL_R1)) R1 = true;
    else R1 = false;

    if(controller.get_digital_new_press(DIGITAL_R2)) R2 = true;
    else R2 = false;

    if(controller.get_digital_new_press(DIGITAL_B)) B = true;
    else B = false;

    if(controller.get_digital_new_press(DIGITAL_DOWN)) DOWN = true;
    else DOWN = false;
}

void reset() {
    lf.tare_position();
    lm.tare_position();
    lb.tare_position();
    rf.tare_position();
    rm.tare_position();
    rb.tare_position();
}

