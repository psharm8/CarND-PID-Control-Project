#include <iostream>
#include <limits>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

#define WAIT_STEPS 100

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    first = true;
}

void PID::UpdateError(double cte) {
    if (this->first)
    {
        p_error = cte;
        first = false;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return (Kp*p_error + Kd*d_error + Ki*i_error);
}

