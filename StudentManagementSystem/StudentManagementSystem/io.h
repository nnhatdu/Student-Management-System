#include "Header.h"
#include "function.h"

#ifndef IO_H
#define IO_H
void ReadStudentFromFile(string dir, vector<User>& users);
void ReadLecturerFromFile(string dir, vector<User>& users);
void ReadStaffFromFile(string dir, vector<User>& users);
void ReadCourseFromFile(string dir, vector<Course>& courses);
void ReadScheduleFromFile(string dir, vector<Schedule>& schedules);
void ReadHistoryFromFile(string dir, vector<History>& history);
void ReadScoreFromFile(string dir, vector<Score>& scores);
void WriteStudentToFile(string dir, vector<User>& users);
void WriteLecturerToFile(string dir, vector<User>& users);
void WriteStaffToFile(string dir, vector<User>& users);
void WriteCourseToFile(string dir, vector<Course>& courses);
void WriteScheduleToFile(string dir, vector<Schedule>& schedules);
void WriteHistoryToFile(string dir, vector<History>& history);
void WriteScoreToFile(string dir, vector<Score>& scores);
void ReadConfig(string& year, string& semester);
void WriteConfig(string& year, string& semester);
void WriteFile(vector<User>& users);

void ReadStudentsOfCourse(string dir, vector<StudentOfCourse>& students);
void WriteStudentsOfCourse(string dir, vector<StudentOfCourse>& students);
void ReadConfigFromFile(string dir, vector<Config>& configs);
void WriteConfigToFile(string dir, vector<Config>& configs);
#endif // !IO_H
