#pragma once

#include <iostream>
#include <string>
#include <map>
#include "FrontEnd.h"
#include "../backend/HistoryEvents.h"

void searchEvent()
{
	std::map< std::string, std::string > searchEvent;
	std::string filter, value;
	goToCoordinates(70, 15); setColor(14); std::cout << "Search event by filter: "; std::getline(std::cin, filter);
	goToCoordinates(70, 16); setColor(14); std::cout << "Search event by value: "; std::getline(std::cin, value);
	searchEvent.insert(std::pair<std::string, std::string> (filter, value));
	goToCoordinates(70, 17); setColor(14); std::cout << eventManager.getEventByFilter(searchEvent);
	goToCoordinates(0, 31); std::cout << "\n";
}

void printSearchEvent()
{
	system("CLS");
	setColor(11);
	printLogo();
	printBorder();
	printSoldiers();

	searchEvent();

	system("PAUSE");
	system("CLS");
}