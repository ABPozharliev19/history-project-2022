#pragma once

constexpr const char* createDatabase =
"CREATE TABLE IF NOT EXISTS HistoryEvents("
"    EventId INTEGER NOT NULL,"
"    Month VARCHAR NOT NULL,"
"    Year VARCHAR NOT NULL,"
"    Location VARCHAR NOT NULL,"
"    Reason VARCHAR,"
"    Leader VARCHAR,"
"    Participants VARCHAR,"
"    Results VARCHAR NOT NULL, "
"    PRIMARY KEY(EventId)"
")";