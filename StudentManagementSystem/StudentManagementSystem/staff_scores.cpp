#include "staff_scores.h"
#include "graph.h"
#include "staff_courses.h"
int xCount = 1;
void SearchViewScore(vector<Score>& scores, vector <Course>& courses) {
blabla:
	smScreen();
	string CoursesID;
	ViewListCourses(courses, "ALL");
	textcolor(11);
	xCount = 20;
	gotoxy(40, xCount + 1); cout << "Enter course code: ";
	textcolor(8); getline(cin, CoursesID);
	cout << fixed << setprecision(1);
	textcolor(14);
	gotoxy(40, xCount + 3); cout << "   ID   | Mid | Lab | Final | Total ";
	gotoxy(40, xCount + 4); cout << "--------+-----+-----+-------+-------";
	for (int i = 0; i < scores.size(); ++i) {
		if (CoursesID == scores[i].CourseID) {
			gotoxy(40, xCount + 5);
			cout << setw(8) << scores[i].StudentID << "|";
			cout << setw(5) << scores[i].MidScore << "|";
			cout << setw(5) << scores[i].LabScore << "|";
			cout << setw(7) << scores[i].FinalScore << "|";
			cout << setw(6) << scores[i].TotalScore << "  " << '\n';
			xCount++;
		}
	}
	PauseScreen(45, xCount + 7);
}

void ExportScore(vector<Score> scores) {
	resizeConsole(1000, 600);
	system("cls");
	smScreen();

	string dir;
	textcolor(11);
	gotoxy(20, 13);
	cout << "Enter the path to export: ";
	getline(cin, dir);
	string CourseID;
	gotoxy(20, 14);
	cout << "Enter course code: ";
	getline(cin, CourseID);
	bool check = true;
	for (int i = 0; i < scores.size(); ++i) {
		if (CourseID == scores[i].CourseID) {
			check = false;
			break;
		}
	}
	if (!check) {
		if (dir.substr(dir.length() - 1, 1) == "\\") 
			dir.std::string::append("ExportScore").append(CourseID).append(".csv");
		else dir.std::string::append("\\ExportScore").append(CourseID).append(".csv");
		ofstream o;
		o.open(dir);
		o << "Course code,Year,Semester,Student ID,Midterm score,Lab score,Final score,Total score" << endl;
		for (int i = 0; i < scores.size(); ++i) {
			if (CourseID == scores[i].CourseID) {
				o << scores[i].CourseID << ',' << scores[i].Year << ',' << scores[i].Semester << ',' << scores[i].StudentID << ',' << scores[i].MidScore << ',' << scores[i].LabScore << ',' << scores[i].FinalScore << ',' << scores[i].TotalScore << endl;
			}
		}
		textcolor(14);
		gotoxy(56, 16);
		cout << "Export successfully" << endl;
		o.close();
	}
	else {
		textcolor(12);
		gotoxy(58, 16);
		cout << "No course code." << endl;
	}
	PauseScreen(53, 18);
}