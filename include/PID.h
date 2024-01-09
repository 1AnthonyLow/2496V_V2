#include "main.h"

#define TURN_MAX_INTEGRAL 127
#define TURN_INTEGRAL_KICK 5
class PID {
public:
  float error = 0;
  float m_kp;
  float m_ki;
  float m_kd;
  float prev_error = 0;
  float integral = 0;
  float derivative = 0;
  float power = 0;
  float prev_power = 0;

  PID(float kp, float ki, float kd) {
    m_kp = kp;
    m_ki = ki;
    m_kd = kd;
  }

  void resetVars() {
    error = 0;
    prev_error = 0;
    integral = 0;
    derivative = 0;
    power = 0;
    prev_power = 0;
  }

  float calc(float target, float input, float integral_KI, float maxI) {
    prev_power = power;
    prev_error = error;
    error = target - input;

    derivative = error - prev_error;

    if (std::abs(error) < integral_KI) {
      integral = integral + error;
    } else {
      integral = 0;
    }

    if (integral > 0) {
      integral = std::min(integral, maxI);
    } else {
      integral = std::max(integral, -maxI);
    }

    power = m_kp * error + m_ki * integral + m_kd * derivative;
    return power;
  }
};
