#ifndef STUDENT_H
#define STUDENT_H

#include"Header.h"
#include "function.h"

void CheckIn(User& current, vector<Course>& courses, vector<History>& history);
void ViewCheckInResult(User& current, vector<History>& history);
void ViewScore(User& current, vector<Score>& scores, vector <Course>& courses);
void ViewScheduleStudent(User& current, vector<Schedule>& schedules);

#endif // !STUDENT_H
