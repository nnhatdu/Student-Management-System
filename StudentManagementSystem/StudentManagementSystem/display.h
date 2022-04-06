#ifndef DISPLAY_H
#define DISPLAY_H
#include "Header.h"
#include "standard.h"
#include "lecturer.h"
#include "student.h"
#include "graph.h"
#include "staff_students.h"
#include "staff_courses.h"
#include "staff_schedule.h"
#include "staff_history.h"
#include "staff_scores.h"
#include "staff_lecturers.h"
#include "staff_year_semester.h"

enum Display {
	HOME,
	MENU,
	EXIT,
};
void ShowHomeScreen_User(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student);
void ShowMenuScreen_Staff(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student, string& currentSemester, vector<StudentOfCourse>& students, string& currentYear, vector<Config>& configs);
void ShowMenuScreen_Lecturer(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student, string& currentSemester, vector<StudentOfCourse>& students);
void ShowMenuScreen_Student(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student);
void ShowExitScreen();
void ShowHomeScreen_Guest(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student);
#endif // !DISPLAY_H

