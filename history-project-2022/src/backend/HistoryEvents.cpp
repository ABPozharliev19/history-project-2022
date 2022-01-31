#include "../../include/backend/HistoryEvents.h"

HistoryEvents::HistoryEvents()
{
	int wasConnectionEstablished = sqlite3_open("events.db", &db);
	
	if (wasConnectionEstablished)
	{
		std::cout << "Didn't open database." << std::endl << sqlite3_errmsg(db);
		return;
	}
	
	char* errMsg = NULL;

	int wasDatabaseCreated = sqlite3_exec(db, createDatabase, &HistoryEvents::callback, NULL, &errMsg);

	if (wasDatabaseCreated != SQLITE_OK)
	{
		std::cout << "Couldn't create table"<<std::endl<<errMsg;
		sqlite3_free(errMsg);
	}

	else
	{
		std::cout << "Created the table";
	}
}	

HistoryEvents::~HistoryEvents()
{
	sqlite3_close(db);
}

int HistoryEvents::callback(void* NotUsed, int size, char** data, char** columnName) {
	for (int i = 0; i < size; i++)
	{
		std::cout << columnName[i] << " = " << data[i] ? data[i] : "NULL";
	}
	return 0;
}