#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_coeff, double Ki_coeff, double Kd_coeff) {
  Kp = Kp_coeff;
  Ki = Ki_coeff;
  Kd = Kd_coeff;
  p_error = 0;
  d_error = 0;
  i_error = 0;
}

void PID::UpdateError(double cte) {
  // update the internal error values, used in calculation of the steering value
  d_error = cte - p_error;
  p_error = cte;
  i_error = i_error + cte;
}

double PID::TotalError() {
	return 1;
}

double PID::GetValue() {
  return (-1.0 * Kp * p_error) + (-1.0 * Kd * d_error) + (-1.0 * Ki * i_error);
}