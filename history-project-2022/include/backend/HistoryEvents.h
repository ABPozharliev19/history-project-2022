#pragma once

#include "../../libs/sqlite3.h"

#include <iostream>
#include <string>
#include <map>

class HistoryEvents
{
public:
	HistoryEvents();

	~HistoryEvents();

	bool insertEvent(
		std::string month,
		std::string year,
		std::string location,
		std::string result,
		std::string reason = "NULL",
		std::string leader = "NULL",
		std::string participants = "NULL"
	);

	std::string getAllEvents();

	std::string getEventByFilter(std::map<std::string,
								 std::string> filters);

	bool deleteEventByFilter(std::map<std::string,
									std::string> filters);

private:
	static int callbackCreateTable( 
		void* NotUsed,
		int size,
		char** data,
		char** columnName
	);

	static int callbackSelectEvents(
		void* callback,
		int size,
		char** data,
		char** columnName
	);

	static int callbackDeleteEvents(
		void* notUsed,
		int size,
		char** data,
		char** columnName
	);

private:
	sqlite3* db;

	static constexpr const char* createDatabase =
	"CREATE TABLE IF NOT EXISTS HistoryEvents("
	"    EventId INTEGER PRIMARY KEY AUTOINCREMENT,"
	"    Month VARCHAR NOT NULL,"
	"    Year VARCHAR NOT NULL,"
	"    Location VARCHAR NOT NULL,"
	"    Reason VARCHAR,"
	"    Leader VARCHAR,"
	"    Participants VARCHAR,"
	"    Results VARCHAR NOT NULL"
	")";

	 static std::string resultsSelect;
};