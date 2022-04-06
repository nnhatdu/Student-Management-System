#ifndef STAFF_HISTORY_H
#define STAFF_HISTORY_H
#include "function.h"
#include "Header.h"

void ImportHistory(vector<History>& history);
void ViewHistory(vector<History>& History, vector<Course>& courses);
void ExportHistory(vector<History>& History);
#endif // !STAFF_HISTORY_H
