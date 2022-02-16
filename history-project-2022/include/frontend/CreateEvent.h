#pragma once

#include <iostream>
#include <string>
#include "FrontEnd.h"
#include "../backend/HistoryEvents.h"


void createNewEvent()
{

	std::string month, year, location, reason, leader, participants, result;
	goToCoordinates(70, 15); setColor(14); std::cout << "Event month: "; std::getline(std::cin, month);
	goToCoordinates(70, 16); setColor(14); std::cout << "Event year: "; std::getline(std::cin, year);
	goToCoordinates(70, 17); setColor(14); std::cout << "Event location: "; std::getline(std::cin, location);
	goToCoordinates(70, 18); setColor(14); std::cout << "Event reason: "; std::getline(std::cin, reason);
	goToCoordinates(70, 19); setColor(14); std::cout << "Event leader: "; std::getline(std::cin, leader);
	goToCoordinates(70, 20); setColor(14); std::cout << "Event participants: "; std::getline(std::cin, participants);
	goToCoordinates(70, 21); setColor(14); std::cout << "Event result: "; std::getline(std::cin, result);

	eventManager.insertEvent( month, year, location, reason, leader, participants, result );
}

void printCreateEvent()
{
	system("CLS");
	setColor(11);
	printLogo();
	printBorder();
	printSoldiers();

	createNewEvent();

	goToCoordinates(0, 31); std::cout << "\n";
	system("PAUSE");
	system("CLS");
}