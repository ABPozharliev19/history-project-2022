#pragma once

#include <iostream>
#include "FrontEnd.h"

void printAllEvents()
{
	system("CLS");
	setColor(11);
	printLogo();
	printBorder();
	printSoldiers();

	goToCoordinates(70, 15); setColor(14); std::cout << eventManager.getAllEvents(); 
	goToCoordinates(0, 31); std::cout << "\n";

	system("PAUSE");
	system("CLS");
}