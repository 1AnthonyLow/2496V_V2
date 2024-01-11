#include "robot.h"
#include "util.cpp"
#include "slapper.h"

namespace slapper {
    Timer timer = Timer();
    slapperStates state = idle;
    void run() {
            switch (state)
                {
                // case firing:
                //     cata.move(-127);
                //     if (!cataSwitch.get_value()) {
                //         state = reloading;
                //     }
                //     break;
                // case reloading:
                //     cata.move(-127);
                //     if (cataSwitch.get_value()) {
                //         cata.move(0);
                //         state = idle;
                //     }
                    // break;
                case halfState:
                    if(timer.getTime() < 725) {
                        cata.move(-127);
                    }
                    else {
                        state = idle;
                        cata.move(0);
                    }
                    break;
                case matchloading:
                    cata.move(-127);
                    break;
            
                case idle:
                    break;
            }
    }

    void fire() {
        state = firing;
    }
    void half() {
        state = halfState;
        timer.startTime();
    }

    void matchload() {
        state = matchloading;
    }

    void id(){
        state = idle;
        cata.move(0);
    }

}