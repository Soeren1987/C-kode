/*

 * main.cpp
 *
 *  Created on: 23 Aug 2018
 *      Author: Soeren
 */

#include <iostream>


using namespace std;


int main ( )
{
	char num = '0';

	cout << "Goddag. Jeg er dit interaktive Hej verden program" << endl;

	cout << "vælg mellem 5 citater ved at trykke 1-5 og 9 for at afslutte"
	    << endl;

	cin >> num;

	while (num != '9')
	{
		if (num == '1')
		{
			cout << "Det går nok" << endl;
		}
		else if (num == '2')
		{
			cout << "det er møj fint" << endl;
		}
		else if (num == '3')
		{
			cout << "virker det ikke. brug en større hammer" << endl;
		}
		else if (num == '4')
		{
			cout << "jeg kan næsten smage weekenden" << endl;
		}
		else if (num == '5')
		{
			cout << "det bliver nemt idag og dog" << endl;
		}
		else
		{
			cout << "vælg mellem 5 citater ved at trykke 1-5 og 9 for at afslutte in loop"
			    << endl;
		}
		cin >> num;
	}
	cout << "Tak fordi du anvendte. Hej verden i C++" << endl;

	return 0;
}

