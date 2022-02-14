#pragma once

#include <iostream>
#include <string>
#include <map>
#include "FrontEnd.h"
#include "../backend/HistoryEvents.h"

void updateEvent()
{
	std::map< std::string, std::string > updateEvent;
	std::string filter, value, newValue;
	goToCoordinates(70, 15); setColor(14); std::cout << "Search event by filter: "; std::getline(std::cin, filter);
	goToCoordinates(70, 16); setColor(14); std::cout << "Search event by value: "; std::getline(std::cin, value);
	goToCoordinates(70, 17); setColor(14); std::cout << "Change event value to: "; std::getline(std::cin, newValue);
	updateEvent.insert(std::pair<std::string, std::string>(filter, value));
	goToCoordinates(70, 18); setColor(14); std::cout << eventManager.getEventByFilter(updateEvent);
	goToCoordinates(0, 31); std::cout << "\n";
}

void printUpdateEvent()
{
	system("CLS");
	setColor(11);
	printLogo();
	printBorder();
	printSoldiers();

	updateEvent();

	system("PAUSE");
	system("CLS");
}