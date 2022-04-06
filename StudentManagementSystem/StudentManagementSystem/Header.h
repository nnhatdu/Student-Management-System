#ifndef HEADER_H
#define HEADER_H
#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <cstdint>
#include <Windows.h>
#include "vector.h"
using namespace std;

const string PASSWORD_DEFAULT = "password";

enum UserTypes
{
	STUDENT,
	STAFF,
	LECTURER
};

enum DaysOfWeek
{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

struct Date
{
	int Day;
	int Month;
	int Year;
	
};

struct Time
{
	int Hour;
	int Minute;
};

struct User
{
	string Username;
	string Fullname;
	string EmailAddress;
	string Phone;
	Date DOB;
	UserTypes Type;
	string Password;
	string Class;
	bool Gender;
	bool isFirstLogin;
};

struct Course
{
	string CourseID;
	string Year;
	int Semester;
	string CourseName;
	string LecturerUsername;
	string Class;
};
struct Config {
	string Year;
	int Semester;
};
struct Schedule {
	string CourseID;
	string Year;
	int Semester;
	string Class;
	Date DateBegin;
	Date DateEnd;
	Time TimeBegin;
	Time TimeEnd;
	DaysOfWeek daysOfWeek;
};

struct History
{
	string CourseID;
	string Year;
	string Class;
	int Semester;
	string StudentID;
	int Week;
	bool Check;
};

struct Score
{
	string CourseID;
	string Year;
	int Semester;
	string StudentID;
	float MidScore;
	float LabScore;
	float FinalScore;
	float TotalScore;
};

struct StudentOfCourse
{
	string CourseID;
	string Year;
	int Semester;
	string CourseName;
	string Class;
	string LecturerUsername;
	string Username;
	string Fullname;
};

#endif
