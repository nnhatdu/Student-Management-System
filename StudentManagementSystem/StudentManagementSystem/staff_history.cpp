#include "staff_history.h"
#include "graph.h"
#include "staff_courses.h"
int zCount = 1;

void ImportHistory(vector<History>& history) {
	smScreen();

	ifstream f;
	string dir;
	textcolor(11);
	gotoxy(40, 13);
	cout << "Input the path of csv file: ";
	textcolor(8); getline(cin, dir);
	f.open(dir);
	if (!f.is_open()) {
		textcolor(12);
		gotoxy(45, 15);
		cout << "Cannot find csv. Please try again." << endl;
		PauseScreen(45, 17);
		return;
	}
	while (!f.eof()) {
		History his;
		getline(f, his.CourseID, ',');
		getline(f, his.Year, ',');
		f >> his.Semester;
		f.ignore(100, ',');
		getline(f, his.Class, ',');
		getline(f, his.StudentID, ',');
		f >> his.Week;
		f.ignore(100, '\n');
		his.Check = true;
		history.push_back(his);
	}
	f.close();
}

void ViewHistory(vector<History>& History, vector<Course>& courses) {
	smScreen();

	string CoursesID;
	int byeah = 0;
	ViewListCourses(courses, "ALL");

	zCount = 16 + courses.size();
	textcolor(11);
	gotoxy(40, zCount);
	cout << "Enter course ID: ";
	getline(cin, CoursesID);
	
	textcolor(11);
	gotoxy(45, zCount + 2); 
	cout << "List attendance of course: " << endl;

	textcolor(14);
	
	for (int i = 0; i < History.size(); ++i) History[i].Check = true;
	gotoxy(43, zCount + 4); cout << "    ID    |   Code   | Sem |  Class  | Week " << endl;
	gotoxy(43, zCount + 5); cout << "----------+----------+-----+---------+------" << endl;

	for (int i = 0; i < History.size(); ++i) 
	{
		if (History[i].CourseID == CoursesID && History[i].Check == true) 
		{
			gotoxy(43, zCount + 6);
			cout << setw(9) << History[i].StudentID << " |";
			cout << setw(9) << History[i].CourseID << " |";
			cout << setw(3) << History[i].Semester << "  |";
			cout << setw(8) << History[i].Class << " |";
			for (int j = i; j < History.size(); j++)
			{
				if (History[i].StudentID == History[j].StudentID && History[j].CourseID == CoursesID) {
					cout << setw(4) << History[j].Week;
					History[j].Check = false;
				}
			}
			zCount++;
		}
	}
	PauseScreen(45, zCount + 8);
}

void ExportHistory(vector<History>& History) {
	resizeConsole(1000, 600);
	system("cls");
	smScreen();

	string dir;
	textcolor(11);
	gotoxy(20, 13);
	cout << "Enter the path to export: ";
	getline(cin, dir);
	if (dir.substr(dir.length() - 1, 1) == "\\")
		dir.std::string::append("ExportAttendance").append(".csv");
	else dir.std::string::append("\\ExportAttendance").append(".csv");
	ofstream o;
	o.open(dir);
	o << "Courses ID,Year,Semester,Students ID,Week" << endl;
	for (int i = 0; i < History.size(); ++i) {
		o << History[i].CourseID << "," << History[i].Year << "," << History[i].Semester << "," << History[i].Class << "," << History[i].StudentID << "," << History[i].Week << endl;
	}
	o.close();
	textcolor(14);
	gotoxy(56, 15);
	cout << "Export successfully" << endl;
	PauseScreen(53, 17);
}