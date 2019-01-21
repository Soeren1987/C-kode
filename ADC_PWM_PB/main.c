/*
 * main.c
 *
 *  Created on: 21 Nov 2018
 *      Author: Soeren
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "control.h"

#define PERIODE 10000000  // set periode to 10 ms fcpu is 1 GHz / 100 Hz = 10e7

int main() {
	int duty = 0;

	init_pwm(PERIODE);
	int i = 0;
	while (i != 3000) {
		duty = read_adc();
		printf("duty cycle is %d \n", duty);
		set_pwm(duty, PERIODE);
		usleep(10000); // 10 ms update time
		i++;
	}
	shutdown();
	return 0;
}

