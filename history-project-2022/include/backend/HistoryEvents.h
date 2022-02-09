#pragma once

#include "../../libs/sqlite3.h"

#include <iostream>
#include <string>

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

private:
	static int callbackCreateTable( 
		void* NotUsed,
		int argc,
		char** argv,
		char** azColName
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
};