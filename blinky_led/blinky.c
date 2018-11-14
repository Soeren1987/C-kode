/*
 * blinky.c
 *
 *  Created on: 13 Nov 2018
 *      Author: Soeren
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	FILE * export_file = NULL; //declare pointers
	FILE * IO_direction = NULL;
	FILE * IO_value = NULL;

	char str1[] = "0";
	char str2[] = "1";
	char str3[] = "out";
	char str[] = "23";

	//this part here exports gpio23

	if ((export_file = fopen("/sys/class/gpio/export", "w")) == NULL) {
		fwrite(str, 1, sizeof(str), export_file);
		fclose(export_file);
	}
	//this part here sets the direction of the pin

	IO_direction = fopen("/sys/class/gpio/gpio23/direction", "w");
	fwrite(str3, 1, sizeof(str3), IO_direction); //set the pin to HIGH
	fclose(IO_direction);
	sleep(1);

	for (int i = 0; i < 10; i++) { //blink LED 10 times
		IO_value = fopen("/sys/class/gpio/gpio23/value", "w");
		fwrite(str2, 1, sizeof(str2), IO_value); //set the pin to HIGH
		fclose(IO_value);
		printf("HIGH\n");
		sleep(1); //delay for a second

		IO_value = fopen("/sys/class/gpio/gpio23/value", "w");
		fwrite(str1, 1, sizeof(str1), IO_value); //set the pin to LOW
		fclose(IO_value);
		printf("LOW\n");
		sleep(1); //delay for a second
	}
	return 0;
}

