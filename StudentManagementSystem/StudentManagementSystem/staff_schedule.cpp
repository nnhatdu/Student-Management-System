#include "staff_schedule.h"
#include "function.h"
#include "graph.h"
#include "io.h"

void printSchedule(Schedule& schedule) {
	cout << "Course code: " << schedule.CourseID << endl;
	cout << "Year: " << schedule.Year << endl;
	cout << "Semester: " << schedule.Semester << endl;
	cout << "Class: " << schedule.Class << endl;
	cout << "Date: " << DateToString(schedule.DateBegin) << " - " << DateToString(schedule.DateEnd) << endl;
	cout << "Time: " << TimeToString(schedule.TimeBegin) << " - " << TimeToString(schedule.TimeEnd) << endl;
	cout << "Day of week: " << DOWToString(schedule.daysOfWeek) << endl;
}

string findLecturer(vector<Course>& courses, Schedule& s, string temp) {
	for (int i = 0; i < courses.size(); ++i) {
		if (courses[i].CourseID == s.CourseID && courses[i].Year == s.Year && courses[i].Semester == s.Semester)
			temp = courses[i].LecturerUsername;
		return temp;
	}
	temp = "N/A";
	return temp;
}

bool dateConflict(Date& b1, Date& e1, Date& b2, Date& e2) {
	Date b = b1 >  b2 ? b1 : b2;
	Date e = e1 < e2 ? e1 : e2;
	return (b <= e);
}

bool timeConflict(Time& b1, Time& e1, Time& b2, Time& e2) {
	Time b = b1>b2?b1:b2;
	Time e = e1<e2?e1:e2;
	return (b <= e);
}

bool checkSchedule(vector<Course>& courses, vector<Schedule>& schedules, Schedule& schedule, Schedule& conflictedSchedule) {
	string sLecturer;
	findLecturer(courses, schedule, sLecturer);
	for (int i = 0; i < schedules.size(); ++i) {
		if ((dateConflict(schedules[i].DateBegin, schedules[i].DateEnd, schedule.DateBegin, schedule.DateEnd) && timeConflict(schedules[i].TimeBegin, schedules[i].TimeEnd, schedule.TimeBegin, schedule.TimeEnd) && schedules[i].daysOfWeek == schedule.daysOfWeek)
|| (schedules[i].CourseID == schedule.CourseID && schedules[i].Year == schedule.Year && schedules[i].Semester == schedule.Semester && schedules[i].Class == schedule.Class))
		{
			string iLecturer;
			findLecturer(courses, schedules[i], iLecturer);
			cout << iLecturer << endl;
			if (schedules[i].Class == schedule.Class || iLecturer == sLecturer) {
				conflictedSchedule = schedules[i];
				return true;
			}
		}
	}
	return false;
}

bool confirmUpdate(vector<Course>& courses, vector<Schedule>& schedules, Schedule schedule, string action) {
	Schedule conflictedSchedule;
	bool check = checkSchedule(courses, schedules, schedule, conflictedSchedule);
	if (check) {
		cout << "Warning: the entered schedule conflicted with the following schedule" << endl;
		printSchedule(conflictedSchedule);
		cout << action << " anyway (Y/N)? ";
		char c = _getch();
		if (c == 'n' || c == 'N') {
			cout << "\nOperation aborted." << endl;
			PauseScreen(52, 30);
			return false;
		}
	}
	return true;
}

void ImportSchedule(vector<Course>& courses, vector<Schedule>& schedules) {
	string dir;
	cout << "Enter the csv file path: ";
	getline(cin, dir, '\n');
	ifstream f;
	f.open(dir);
	if (!f.is_open()) {
		cout << "No csv file with such path was found. Please try again." << endl;
		PauseScreen(45, 3);
		return;
	}
	string Class;
	string temp;
	getline(f, temp,',');
	getline(f, Class, '\n');
	getline(f, temp);
	int scheduleCount = 0;
	while (!f.eof()) {
		Schedule schedule;
		Course cour;
		getline(f, temp, ',');
		schedule.CourseID = temp;
		cour.CourseID = temp;
		getline(f, temp, ',');
		schedule.Year = temp;
		cour.Year = temp;
		getline(f, temp, ',');
		schedule.Semester = StringToInt(temp);
		cour.Semester = StringToInt(temp);
		getline(f, cour.CourseName, ',');
		getline(f, cour.LecturerUsername, ',');
		schedule.Class = Class;
		cour.Class = Class;
		getline(f, temp, ',');
		schedule.DateBegin = StringToDate(temp);
		getline(f, temp, ',');
		schedule.DateEnd = StringToDate(temp);
		getline(f, temp, ',');
		schedule.TimeBegin = StringToTime(temp);
		getline(f, temp, ',');
		schedule.TimeEnd = StringToTime(temp);
		getline(f, temp, '\n');
		schedule.daysOfWeek = StringToDOW(temp);
		string s;
		findLecturer(courses, schedule, s);
		if (s == "N/A") continue;
		if (!confirmUpdate(courses, schedules, schedule, "Import"))
			continue;
		schedules.push_back(schedule);
		courses.push_back(cour);
		scheduleCount++;
	}
	f.close();
	cout << scheduleCount << " schedules is imported." << endl;
	PauseScreen(45, 6);
}

void AddSchedule(vector<Course>& courses, vector<Schedule>& schedules) {
	string temp;
	Schedule schedule;
	cout << "Enter course code: ";
	getline(cin, schedule.CourseID);
	cout << "Enter school year: ";
	getline(cin, schedule.Year);
	cout << "Enter semester: ";
	cin >> schedule.Semester;
	getline(cin, temp);
	string s;
	findLecturer(courses, schedule, s);
	if (s == "N/A") {
		cout << "Course not found with given information." << endl;
		PauseScreen(45, 5);
		return;
	}
	cout << "Enter class: ";
	getline(cin, schedule.Class);
	cout << "Enter start date (dd/mm/yyyy): ";
	getline(cin, temp);
	schedule.DateBegin = StringToDate(temp);
	cout << "Enter end date (dd/mm/yyyy): ";
	getline(cin, temp);
	schedule.DateEnd = StringToDate(temp);
	cout << "Enter start time (hh:mm): ";
	getline(cin, temp);
	schedule.TimeBegin = StringToTime(temp);
	cout << "Enter end time (hh:mm): ";
	getline(cin, temp);
	schedule.TimeEnd = StringToTime(temp);
	cout << "Enter day of week (e.g. Monday): ";
	getline(cin, temp);
	schedule.daysOfWeek = StringToDOW(temp);
	if (!confirmUpdate(courses, schedules, schedule, "Add"))
		return;
	schedules.push_back(schedule);
	cout << "Operation successful." << endl;
	WriteScheduleToFile("Schedule.csv", schedules);
	PauseScreen(45, 11);
}

void EditSchedule(vector<Course>& courses, vector<Schedule>& schedules) {
	string temp;
	string CoursesID;
	string Year;
	string Class;
	int count = 1;
	cout << "Enter course code: ";
	getline(cin, CoursesID);
	cout << "Enter school year: ";
	getline(cin, Year);
	cout << "Enter semester: ";
	getline(cin, temp);
	int Semester = StringToInt(temp);
	cout << "Enter class: ";
	getline(cin, Class);
	int iSchedule;
	for (iSchedule = 0; iSchedule < schedules.size(); ++iSchedule) {
		if (schedules[iSchedule].CourseID == CoursesID && schedules[iSchedule].Year == Year && 
			schedules[iSchedule].Semester == Semester && schedules[iSchedule].Class == Class)
			break;
	}
	if (iSchedule == schedules.size()) {
		cout << "Schedule not found with given information." << endl;
		PauseScreen(45, 6);
		return;
	}

	Schedule editedSchedule = schedules[iSchedule];
	blabla:
	cout << "1. Edit course code" << endl;
	cout << "2. Edit school year" << endl;
	cout << "3. Edit semester" << endl;
	cout << "4. Edit class" << endl;
	cout << "5. Edit start date" << endl;
	cout << "6. Edit end date" << endl;
	cout << "7. Edit state time (from)" << endl;
	cout << "8. Edit end time (to)" << endl;
	cout << "9. Edit day of week" << endl;
	cout << "0. Cancel" << endl;

	cout << "Please enter an action (0-9): ";
	string action; 
	getline(cin, action);

	if (action == "1") {
		cout << "Enter new course code: ";
		getline(cin, editedSchedule.CourseID);
	}
	else if (action == "2") {
		cout << "Enter new school year: ";
		getline(cin, editedSchedule.Year);
	}
	else if (action == "3") {
		cout << "Enter semester: ";
		getline(cin, temp);
		editedSchedule.Semester = StringToInt(temp);
	}
	else if (action == "4") {
		cout << "Enter class: ";
		getline(cin, editedSchedule.Class);
	}
	else if (action == "5") {
		cout << "Enter new start date (dd/mm/yyyy): ";
		getline(cin, temp);
		editedSchedule.DateBegin = StringToDate(temp);
	}
	else if (action == "6") {
		cout << "Enter new end date (dd/mm/yyyy): ";
		getline(cin, temp);
		editedSchedule.DateEnd = StringToDate(temp);
	}
	else if (action == "7") {
		cout << "Enter new start time (hh:mm): ";
		getline(cin, temp);
		editedSchedule.TimeBegin = StringToTime(temp);
	}
	else if (action == "8") {
		cout << "Enter new end time (hh:mm): ";
		getline(cin, temp);
		editedSchedule.TimeEnd = StringToTime(temp);
	}
	else if (action == "9") {
		cout << "Enter new date of week (e.g Monday): ";
		getline(cin, temp);
		editedSchedule.daysOfWeek = StringToDOW(temp);
	}
	else if (action == "0") {
		cout << "Operation aborted." << endl;
		PauseScreen(45, 17);
		return;
	}

	string s;
	findLecturer(courses, editedSchedule, s);
	if (s == "N/A") {
		cout << "Course not found with given information." << endl;
		PauseScreen(45, 17);
		return;
	}

	if (!confirmUpdate(courses, schedules, editedSchedule, "Edit"))
		return;

	schedules[iSchedule] = editedSchedule;
	cout << "\nOperation successful." << endl;
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y')
	{
		count++;
		cout << endl;
		goto blabla;
	}
	WriteScheduleToFile("Schedule.csv", schedules);
	PauseScreen(52, 7 + count * 24);
}

void RemoveSchedule(vector<Schedule>& schedules) {
	string CoursesID;
	string Year;
	string temp;
	string Class;

	cout << "Enter course code: ";
	getline(cin, CoursesID);
	cout << "Enter school year: ";
	getline(cin, Year);
	cout << "Enter semester: ";
	getline(cin, temp);
	int Semester = StringToInt(temp);
	cout << "Enter class: ";
	getline(cin, Class);

	int iSchedule;
	for (iSchedule = 0; iSchedule < schedules.size(); ++iSchedule) {
		if (schedules[iSchedule].CourseID == CoursesID && schedules[iSchedule].Year == Year && 
			schedules[iSchedule].Semester == Semester && schedules[iSchedule].Class == Class)
			break;
	}
	if (iSchedule == schedules.size()) {
		cout << "Schedule not found with given information." << endl;
		PauseScreen(45, 6);
		return;
	}

	schedules.erase(iSchedule);
	cout << "Removed successfully." << endl;
	WriteScheduleToFile("Schedule.csv", schedules);
	PauseScreen(45, 6);
}

void ViewSchedulesStaff(vector<Schedule>& schedules) {
	string Class;
	cout << "Enter class (enter * to view schedule of all class): ";
	getline(cin, Class);

	cout << "  Code  |   Year  | Sem| Class | Start At |  End At  | From|  To |Day of week" << endl;
	cout << "--------+---------+----+-------+----------+----------+-----+-----+-----------" << endl;
	//	cout << "  CS162|2019-2020|   2| 19CLC9|03/03/2020|06/06/2020|07:30|11:30|   Wednesday"

	for (int i = 0; i < schedules.size(); ++i) {
		if (Class == "*" || schedules[i].Class == Class) {
			cout << setw(7) << schedules[i].CourseID << "|";
			cout << setw(9) << schedules[i].Year << "|";
			cout << setw(4) << schedules[i].Semester << "|";
			cout << setw(7) << schedules[i].Class << "|";
			cout << setw(10) << DateToString(schedules[i].DateBegin) << "|";
			cout << setw(10) << DateToString(schedules[i].DateEnd) << "|";
			cout << setw(5) << TimeToString(schedules[i].TimeBegin) << "|";
			cout << setw(5) << TimeToString(schedules[i].TimeEnd) << "|";
			cout << setw(10) << DOWToString(schedules[i].daysOfWeek) << endl;
		}
	}

	PauseScreen(45, 7 + schedules.size());
}