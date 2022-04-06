#ifndef STAFF_YEAR_SEMESTER_H
#define STAFF_YEAR_SEMESTER_H
#include "Header.h"
#include "function.h"

void CreateYearSemester(vector<Config>& configs, string& currentYear, string& currentSemester);
void UpdateYearSemester(vector<Config>& configs, string& currentYear, string& currentSemester);
void RemoveYearSemester(vector<Config>& configs, string& currentYear, string& currentSemester);
void ViewYearSemester(vector<Config>& configs);


#endif // STAFF_YEAR_SEMESTER_H
