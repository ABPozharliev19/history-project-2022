#include "include/backend/HistoryEvents.h"
#include "include/frontend/MainMenu.h"

int main()
{
	HistoryEvents eventManager;

	std::map<std::string, std::string> gosho;

	gosho.insert({ "EventId", "2"});

	eventManager.deleteEventByFilter(gosho);

	eventManager.getAllEvents();
}

