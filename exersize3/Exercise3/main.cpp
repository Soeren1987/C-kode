/*
 * main.cpp
 *
 *  Created on: 7 Jul 2016
 *      Author: klaus
 */

#include "Options.h"
#include <iostream>

using namespace std;

/*
 * This program demonstrates the Options calls, which is able to handle
 * command line arguments to the program.
 * In this version it will only handle -<letter> options, i.e. -a or -o
 */
int main (int argC, char const **argV)
{
	Options opts (argC, argV);

	if (opts.isPresent ('a'))
	{
		cout << "option A was set on the command line." << endl;
	}
	if (opts.isPresent('b'))
	{
		cout << "option B was set on the command line" << endl;
	}

	if (opts.isPresent('o'))
	{
		cout << "option O was set on the command line" << endl;
	}
	return 0;
}

