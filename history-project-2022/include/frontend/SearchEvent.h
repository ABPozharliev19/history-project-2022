#pragma once

#include <iostream>
#include <string>
#include "FrontEnd.h"
#include "../backend/HistoryEvents.h"

void searchEvent()
{
	/*std::string filter;
	goToCoordinates(70, 15); setColor(14); std::cout << "Search event by: "; std::getline(std::cin, filter);
	std::cout << eventManager.getEventByFilter();*/
}

void printSearchEvent()
{
	system("CLS");
	setColor(11);
	printLogo();
	printBorder();

	searchEvent();

	system("PAUSE");
	system("CLS");
}