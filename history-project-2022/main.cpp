#include "include/backend/HistoryEvents.h"
#include "include/frontend/MainMenu.h"

int main()
{
	HistoryEvents eventManager;

	std::map<std::string, std::string> konche;

	konche.insert({ "Month", "0" });

	std::cout<<eventManager.getEventByFilter(konche);
}

