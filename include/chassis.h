#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "main.h"
#include "robot.h"

void move(float lpwr, float rpwr);

void moveTo(float target, int timeout);

void turnTo(float target, int duration, int powerCap = 127);

void arc(float radius, int theta, std::string dir);

void moveTest(float target, int timeout, float power_cap = 127);
void absTurn(float abstarget, int timeout);

void arcTurn(float leftPower, float rightPower, float duration);

void arcTurnRight(float radius, float theta, int timeout);
void arcTurnLeft(float radius, float theta, int timeout);

#endif