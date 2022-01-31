#pragma once

#include "../../libs/sqlite3.h"

#include "SQLStatements.h"

#include <iostream>

class HistoryEvents
{
public:
	HistoryEvents();
	~HistoryEvents();

private:
	static int callback(void* NotUsed, int argc, char** argv, char** azColName);

private:
	sqlite3* db;
};