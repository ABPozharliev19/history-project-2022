#pragma once

#include <iostream>
#include "FrontEnd.h"

void printAllEvents()
{
	system("CLS");
	setColor(11);
	printLogo();
	printBorder();

	goToCoordinates(70, 15); setColor(14); std::cout << eventManager.getAllEvents(); 

	system("PAUSE");
	system("CLS");
}