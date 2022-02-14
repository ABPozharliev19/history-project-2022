#pragma once

#include <iostream>
#include <string>
#include <map>
#include "FrontEnd.h"
#include "../backend/HistoryEvents.h"

void deleteEvent()
{
	std::map< std::string, std::string > deleteEvent;
	std::string filter, value;
	goToCoordinates(70, 15); setColor(14); std::cout << "Search event by filter: "; std::getline(std::cin, filter);
	goToCoordinates(70, 16); setColor(14); std::cout << "Search event by value: "; std::getline(std::cin, value);
	deleteEvent.insert(std::pair<std::string, std::string>(filter, value));
	goToCoordinates(70, 17); setColor(14); std::cout << eventManager.deleteEventByFilter(deleteEvent);
	goToCoordinates(0, 31); std::cout << "\n";
}

void printDeleteEvent()
{
	system("CLS");
	setColor(11);
	printLogo();
	printBorder();
	printSoldiers();

	deleteEvent();

	system("PAUSE");
	system("CLS");
}