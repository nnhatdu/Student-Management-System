#ifndef STAFF_SCHEDULE_H
#define STAFF_SCHEDULE_H
#include "Header.h"

void ImportSchedule(vector<Course>& courses, vector<Schedule>& schedules);
void AddSchedule(vector<Course>& courses, vector<Schedule>& schedules);
void EditSchedule(vector<Course>& courses, vector<Schedule>& schedules);
void RemoveSchedule(vector<Schedule>& schedules);
void ViewSchedulesStaff(vector<Schedule>& schedules);

#endif // STAFF_SCHEDULE_H