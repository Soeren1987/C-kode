/*
 * control.c
 *
 *  Created on: 21 Nov 2018
 *      Author: Soeren
 */

#include "control.h"

int read_adc() {

	FILE * adc_file = NULL;

	char val[4];
	int res = 0;

	adc_file = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");
	if (adc_file == NULL) {
		printf("could't open file \n");
		exit(EXIT_FAILURE);
	}

	fread(val, sizeof(val), 4, adc_file);

	res = atoi(val);

	if ((fclose(adc_file)) != 0) {
		printf("could't close the adc_file\n");
		exit(EXIT_FAILURE);
	}

	return res * 100 / 4096;  // return procent af analog value
}

void init_pwm(int periode) {
	state = setup;

	FILE * period = NULL;
	/*
	 * setup pin PWM0 to pwm signal on pin P1 36 on PB
	 *
	 * system()  executes a command specified in command by calling /bin/sh -c command
	 */
	system("./setup_pwm_p1_36");

	char str1[20];
	// make int to a string
	sprintf(str1, "%d", periode);
	period = fopen("/sys/class/pwm/pwm-0:0/period", "w");
	if (period == NULL) {
		printf("could't open file \n");
		exit(EXIT_FAILURE);
	}
	fwrite(str1, 1, sizeof(str1), period);

	if ((fclose(period)) != 0) {
		printf("could't close the period_file\n");
		exit(EXIT_FAILURE);
	}

}

void set_pwm(int duty, int time) {

	FILE * Duty_c = NULL;
	FILE * run = NULL;
	int res = 0;

	res = (duty * time) / 100;

	char str2[20];
	char str3[] = "1";
	// make a integer to a string
	sprintf(str2, "%d", res);
	/*
	 * put the value in the file to set duty cycle
	 */
	Duty_c = fopen("/sys/class/pwm/pwm-0:0/duty_cycle", "w");
	if (Duty_c == NULL) {
		printf("could't open file \n");
		exit(EXIT_FAILURE);
	}

	fwrite(str2, 1, sizeof(str2), Duty_c);

	if ((fclose(Duty_c)) != 0) {
		printf("could't close the Duty_c_file\n");
		exit(EXIT_FAILURE);
	}
	/*
	 * enable the pwm to run, with the new configuration
	 */
	if (state == setup) {
		run = fopen("/sys/class/pwm/pwm-0:0/enable", "w");
		if (run == NULL) {
			printf("could't open file \n");
			exit(EXIT_FAILURE);
		}

		fwrite(str3, 1, sizeof(str3), run);

		if ((fclose(run)) != 0) {
			printf("could't close the run_file\n");
			exit(EXIT_FAILURE);
		}
		state = running;
	}

}
void shutdown() {
	FILE * enable = NULL;
	FILE * unexport = NULL;

	char str[] = "0";

	enable = fopen("/sys/class/pwm/pwm-0:0/enable", "w");

	if (enable == NULL) {
		printf("could't open enable file \n");
		exit(EXIT_FAILURE);
	}
	fwrite(str, 1, sizeof(str), enable);

	if ((fclose(enable)) != 0) {
		printf("could't close the enable_file\n");
		exit(EXIT_FAILURE);
	}

	unexport = fopen("/sys/class/pwm/pwmchip0/unexport", "w");

	if (unexport == NULL) {
		printf("could't open unexport file \n");
		exit(EXIT_FAILURE);
	}
	fwrite(str, 1, sizeof(str), unexport);

	if ((fclose(unexport)) != 0) {
		printf("could't close the unexport_file\n");
		exit(EXIT_FAILURE);
	}

}
