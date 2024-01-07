#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "main.h"
#include "robot.h"

void move(float lpwr, float rpwr);

void moveTo(float target, int duration, int exitTime, int powerCap);

void turnTo(float target, int duration, int exitTime, int powerCap);

void arc(float radius, int theta, std::string dir);

#endif