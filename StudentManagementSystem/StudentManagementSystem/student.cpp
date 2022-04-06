#include "student.h"
#include "graph.h"
#include "io.h"
#include "staff_courses.h"
int yCount = 1;
void CheckIn(User& current, vector<Course>& courses, vector<History>& history) {
	string CoursesID, Year, temp, Class;
	int Semester, Week;
	ViewListCourses(courses, "ALL");
	yCount = 20;
	textcolor(11);
	gotoxy(45, yCount);
	cout << "Input Course Code: ";
	textcolor(8); getline(cin, CoursesID);
	
	textcolor(11);
	gotoxy(45, yCount + 1); cout << "Input Year: ";
	textcolor(8); getline(cin, Year);
	
	textcolor(11);
	gotoxy(45, yCount + 2); cout << "Input Semester: ";
	textcolor(8); getline(cin, temp);
	Semester = StringToInt(temp);

	textcolor(11);
	gotoxy(45, yCount + 3); cout << "Input Class: ";
	textcolor(8); getline(cin, Class);

	textcolor(11);
	gotoxy(45, yCount + 4); cout << "Input Week: ";
	textcolor(8); getline(cin, temp);
	
	Week = StringToInt(temp);
	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].CourseID == CoursesID && courses[i].Year == Year && 
			courses[i].Semester == Semester && courses[i].Class == Class)
		{
			bool checkedIn = false;
			for (int i = 0; i < history.size(); ++i) {
				if (history[i].CourseID == CoursesID && history[i].Year == Year && history[i].Semester == Semester &&
					history[i].StudentID == current.Username && history[i].Class == Class && history[i].Week == Week) {
					checkedIn = true;
					break;
				}
			}
			if (checkedIn) {
				gotoxy(50, yCount + 6);
				textcolor(12);
				cout << "Already checked in." << endl;
				PauseScreen(52, yCount + 8);
				return;
			}
			else {
				History checkin;
				checkin.CourseID = courses[i].CourseID;
				checkin.Year = courses[i].Year;
				checkin.Semester = courses[i].Semester;
				checkin.Class = courses[i].Class;
				checkin.StudentID = current.Username;
				checkin.Week = Week;
				history.push_back(checkin);
				gotoxy(47, yCount + 6);
				textcolor(14);
				cout << "Check in successfully." << endl;
				WriteHistoryToFile("History.csv", history);
				PauseScreen(52, yCount + 8);
				return;
			}
		}
		else if (i == courses.size() - 1) {
			gotoxy(47, yCount + 6);
			textcolor(12); cout << "Course not found with given information." << endl;
			PauseScreen(52, yCount + 8);
			return;
		}
	}
}

void ViewCheckInResult(User& current, vector<History>& history) {
	smScreen();
	yCount = 13;
	textcolor(14);
	gotoxy(45, yCount); cout << "   Code   |    Year   | Sem |  Class  | Week " << endl;
	gotoxy(45, yCount + 1); cout << "----------+-----------+-----+---------+------" << endl;
	for (int i = 0; i < history.size(); ++i) {
		if (history[i].StudentID == current.Username) {
			gotoxy(45, yCount + 2);
			cout << setw(9) << history[i].CourseID << " |";
			cout << setw(10) << history[i].Year << " |";
			cout << setw(3) << history[i].Semester << "  |";
			cout << setw(8) << history[i].Class << " |";
			cout << setw(4) << history[i].Week << endl;
			yCount++;
		}
	}
	PauseScreen(52, yCount + 4);
}

void ViewScore(User& current, vector<Score>& scores, vector <Course>& courses) {
	smScreen();
	string CoursesID, Year, temp;
	int Semester;

	ViewListCourses(courses, "ALL");
	yCount = 20;
	
	textcolor(11);
	gotoxy(45, yCount);
	cout << "Input Course Code: ";
	textcolor(8);
	getline(cin, CoursesID);
	
	textcolor(11);
	gotoxy(45, yCount + 1); cout << "Input Year: ";
	textcolor(8);
	getline(cin, Year);
	
	textcolor(11);
	gotoxy(45, yCount + 2); cout << "Input Semester: ";
	textcolor(8);
	getline(cin, temp);
	Semester = StringToInt(temp);
	cout << fixed << setprecision(1);

	textcolor(14);
	gotoxy(45, yCount + 4); cout << "  Code  |   Year  | Sem|  Midterm |    Lab   |   Final  |   Total  " << endl;
	gotoxy(45, yCount + 5); cout << "--------+---------+----+----------+----------+----------+----------" << endl;

	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i].CourseID == CoursesID && scores[i].Year == Year && scores[i].Semester == Semester)
		{
			gotoxy(45, yCount + 6);
			cout << setw(7) << scores[i].CourseID << "|";
			cout << setw(9) << scores[i].Year << "|";
			cout << setw(4) << scores[i].Semester << "|";
			cout << setw(10) << scores[i].MidScore << "|";
			cout << setw(10) << scores[i].LabScore << "|";
			cout << setw(10) << scores[i].FinalScore << "|";
			cout << setw(9) << scores[i].TotalScore << endl;
			yCount++;
		}
		PauseScreen(52, yCount + 8);
		return;
	}
	textcolor(12); gotoxy(45, yCount + 6);
	cout << "Course cannot be found. Please retry." << endl;
	PauseScreen(52, yCount + 8);
}


void ViewScheduleStudent(User& current, vector<Schedule>& schedules) {
	smScreen();
	yCount = 13;
	textcolor(14);
	gotoxy(16, yCount); cout << "   Code   |    Year    | Sem |   Class  |   Start At  |    End At   |  From  |   To   | Day of week " << endl;
	gotoxy(16, yCount + 1); cout << "----------+------------+-----+----------+-------------+-------------+--------+--------+-------------" << endl;
	for (int i = 0; i < schedules.size(); ++i) {
		if (schedules[i].Class == current.Class) {
			gotoxy(16, yCount + 2);
			cout << setw(8) << schedules[i].CourseID << " |";
			cout << setw(11) << schedules[i].Year << " |";
			cout << setw(5) << schedules[i].Semester << "|";
			cout << setw(9) << schedules[i].Class << " |";
			cout << setw(12) << DateToString(schedules[i].DateBegin) << " |";
			cout << setw(12) << DateToString(schedules[i].DateEnd) << " |";
			cout << setw(7) << TimeToString(schedules[i].TimeBegin) << " |";
			cout << setw(7) << TimeToString(schedules[i].TimeEnd) << " |";
			cout << setw(12) << DOWToString(schedules[i].daysOfWeek) << endl;
			yCount++;
		}
	}

	PauseScreen(52, yCount + 3);
}