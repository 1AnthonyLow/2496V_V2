#pragma once

#include "util.h"
namespace slapper{
    enum slapperStates {
        firing,
        halfState,
        idle,
        reloading,
        matchloading,
        move
    };
    extern slapperStates state;
    extern Timer timer;
    extern void run();
    // extern void fire();
    extern void id();
    extern void half();
    extern void matchload();
};