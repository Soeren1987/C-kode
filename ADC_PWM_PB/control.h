/*
 * control.h
 *
 *  Created on: 21 Nov 2018
 *      Author: Soeren
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

enum{
	setup,running
}state;

// read the value from ADC and return in %
int read_adc();
// initialize pwm0 with the Hz we wanted to set
void init_pwm(int periode);
// set the duty cycle for the pwm signal
void set_pwm(int duty, int time);
// lukker ordentlig ned
void shutdown();

#endif /* CONTROL_H_ */
