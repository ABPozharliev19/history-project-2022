#include "../../include/backend/HistoryEvents.h"

std::string HistoryEvents::resultsSelect;

HistoryEvents::HistoryEvents()
{
	int wasConnectionEstablished = sqlite3_open("events.db", &db);
	
	if (wasConnectionEstablished)
	{
		std::cout << "Didn't open database." << std::endl << sqlite3_errmsg(db);
		return;
	}
	
	char* errMsg = NULL;

	int wasDatabaseCreated = sqlite3_exec(db, createDatabase, &HistoryEvents::callbackCreateTable, NULL, &errMsg);

	if (wasDatabaseCreated != SQLITE_OK)
	{
		std::cout << "Couldn't create table"<<std::endl<<errMsg;
		sqlite3_free(errMsg);
	}
}	

HistoryEvents::~HistoryEvents()
{
	sqlite3_close(db);
}

bool HistoryEvents::insertEvent(std::string month,
								std::string year,
								std::string location,
								std::string result,
								std::string reason,
								std::string leader,
								std::string participants
)
{
	std::string quote = "\"";

	std::string insertIntoTable=std::string("INSERT INTO HistoryEvents(Month, Year, Location, Results, Reason, Leader, Participants)") +
								std::string(" VALUES(") +
								quote + month + quote + "," +
								quote + year + quote + "," +
								quote + location + quote + "," +
								quote + result + quote + "," +
								quote + reason + quote + "," +
								quote + leader + quote + "," +
								quote + participants + quote + ")";
					
	char* errMsg;

	if (sqlite3_exec(db, insertIntoTable.c_str(), callbackCreateTable, 0, &errMsg) != SQLITE_OK)
	{
		std::cout<<errMsg;

		sqlite3_free(errMsg);

		return false;
	}
	return true;

}

std::string HistoryEvents::getAllEvents()
{
	const char* getAllEventsQuery = "SELECT EventId, Month, Year, Location, Reason, Leader, Participants, Results FROM HistoryEvents";

	char* errMsg;
	const char* data = "";

	if (sqlite3_exec(db, getAllEventsQuery, callbackSelectEvents, (void*)data, &errMsg) != SQLITE_OK)
	{
		std::cout << errMsg;
		sqlite3_free(errMsg);
	}

	std::cout << resultsSelect;

	return resultsSelect;
}

int HistoryEvents::callbackSelectEvents(void* callback, int size, char** data, char** columnName)
{
	std::string tempResults;

	for (int i = 0; i < size; i++)
	{
		//std::cout << columnName[i] << " = " << data[i] ? data[i] : "NULL";
		tempResults += columnName[i];
		tempResults += " = ";
		tempResults += data[i] ? data[i] : "NULL";
		tempResults += "\n";
	};

	resultsSelect = resultsSelect + tempResults;

	return 0;
}

int HistoryEvents::callbackCreateTable(void* NotUsed, int size, char** data, char** columnName) {
	for (int i = 0; i < size; i++)
	{
		std::cout << columnName[i] << " = " << data[i] ? data[i] : "NULL";
	}
	return 0;
}