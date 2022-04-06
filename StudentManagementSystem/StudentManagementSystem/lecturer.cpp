#include "lecturer.h"
#include "graph.h"
#include "io.h"
#include "staff_courses.h"
int fCount = 1;
void ImportScoreCSV(vector<Score>& scores) {
	smScreen();
	string dir;
	gotoxy(40, 13);
	textcolor(11);
	cout << "Enter the path: ";
	getline(cin, dir, '\n');
	ifstream f;
	f.open(dir);
	if (!f.is_open())
	{
		textcolor(12); gotoxy(45, 15);
		cout << "No csv file was found. Please try again." << endl;
		PauseScreen(45, 17);
		return;
	}
	Score scr;
	string temp;
	getline(f, temp, '\n');
	int countSuccess = 0;
	int countFail = 0;
	while (!f.eof())
	{
		getline(f, temp, ','); 
		getline(f, scr.CourseID, ',');
		getline(f, temp, ','); 
		getline(f, scr.Year, ',');
		getline(f, temp, ','); 
		scr.Semester = StringToInt(temp);
		getline(f, scr.StudentID, ',');
		getline(f, temp, ',');
		scr.MidScore = StringToFloat(temp);
		getline(f, temp, ',');
		scr.LabScore = StringToFloat(temp);
		getline(f, temp, ',');
		scr.FinalScore = StringToFloat(temp);
		getline(f, temp, '\n');
		scr.TotalScore = StringToFloat(temp);
		if (temp != "")
		{
			scores.push_back(scr);
			++countSuccess;
		}
		else ++countFail;
	}
	WriteScoreToFile("Scores.csv", scores);
	f.close();

	textcolor(14);
	gotoxy(45, 15); cout << countSuccess << (countSuccess > 1 ? " students" : " student") << " scores imported." << endl;
	gotoxy(45, 16); cout << countFail << " failed" << endl;
	PauseScreen(45, 18);

}

void EditGrade(vector<Score>& scores, vector <Course>& courses, User& current) {
blabla:
	smScreen();

	ViewListCourses(courses, "ALL");
	fCount = 15 + courses.size();
	string option;
	float newMid, newLab, newFinal, newTotal;
	int i, Semester;
	string CoursesID;
	string Year;
	string ID;
	string temp;
	gotoxy(45, fCount + 2); textcolor(11); cout << "Enter course ID: ";
	textcolor(8); getline(cin, CoursesID);
	
	gotoxy(45, fCount + 3); textcolor(11); cout << "Enter year: ";
	textcolor(8); getline(cin, Year);
	
	gotoxy(45, fCount + 4); textcolor(11); cout << "Enter semester: ";
	textcolor(8); getline(cin, temp);
	Semester = StringToInt(temp);
	
	gotoxy(45, fCount + 5); textcolor(11); cout << "Enter student ID: ";
	textcolor(8); getline(cin, ID);
	
	bool Check = false;
	for (i = 0; i < scores.size(); i++)
		if (CoursesID == scores[i].CourseID && Year == scores[i].Year && Semester == scores[i].Semester && ID == scores[i].StudentID)
		{
			Check = true;
			break;
		}
	if (Check) {
		gotoxy(40, fCount + 7); cout << "    Year   | Sem |    ID    | Mid | Lab | Final | Total " << endl;
		gotoxy(40, fCount + 8); cout << "-----------+-----+----------+-----+-----+-------+-------" << endl;

		for (int i = 0; i < scores.size(); ++i) {
			if (CoursesID == scores[i].CourseID) {
				if (ID == scores[i].StudentID) {
					gotoxy(40, fCount + 9);
					cout << setw(10) << scores[i].Year << " |";
					cout << setw(3) << scores[i].Semester << "  |";
					cout << setw(9) << scores[i].StudentID << " |";
					cout << setw(4) << scores[i].MidScore << " |";
					cout << setw(4) << scores[i].LabScore << " |";
					cout << setw(4) << scores[i].FinalScore << "   |";
					cout << setw(4) << scores[i].TotalScore << '\n';
					fCount++;
				}
			}
		}

		textcolor(14);
		gotoxy(47, fCount + 10);	cout << "1. Midterm score: ";
		gotoxy(47, fCount + 11); cout << "2. Lab score: ";
		gotoxy(47, fCount + 12); cout << "3. Final score: ";
		gotoxy(47, fCount + 13); cout << "4. Total score: ";
		gotoxy(45, fCount + 14); cout << "Choose an ooption (1-4):";
		textcolor(8); getline(cin, option);
		
		if (option == "1") {
			textcolor(11);
			gotoxy(47, fCount + 16);	cout << "Input new midterm score: ";
			textcolor(8);
			cin >> newMid;
			cin.ignore(1000, '\n');
			scores[i].MidScore = newMid;
			WriteScoreToFile("Scores.csv", scores);

			textcolor(14);
			gotoxy(50, fCount + 18);
			cout << "Changed successfully" << endl;
		}

		else if (option == "2") {
			textcolor(11);
			gotoxy(47, fCount + 16); cout << "Input new lab score: ";
			textcolor(8);
			cin >> newLab;
			cin.ignore(1000, '\n');
			scores[i].LabScore = newLab;
			WriteScoreToFile("Scores.csv", scores);

			textcolor(14);
			gotoxy(50, fCount + 18); cout << "Changed successfully" << endl;
		}

		else if (option == "3") {
			textcolor(11);
			gotoxy(47, fCount + 16); cout << "Input new final score: ";
			textcolor(8);
			cin >> newFinal;
			cin.ignore(1000, '\n');
			scores[i].FinalScore = newFinal;
			WriteScoreToFile("Scores.csv", scores);

			textcolor(14);
			gotoxy(50, fCount + 18); cout << "Changed successfully" << endl;
		}

		else if (option == "4") {
			textcolor(11);
			gotoxy(47, fCount + 16); cout << "Input new total score: ";
			textcolor(8);
			cin >> newTotal;
			cin.ignore(1000, '\n');
			scores[i].TotalScore = newTotal;
			WriteScoreToFile("Scores.csv", scores);

			textcolor(14);
			gotoxy(50, fCount + 18); cout << "Changed successfully" << endl;
		}

		else {
			textcolor(12);
			gotoxy(48, fCount + 16); cout << "Entered option is invalid" << endl;
		}
	}
	else
	{
		textcolor(12);
		gotoxy(47, fCount + 7);
		cout << "Data not found, please try again" << endl;
		PauseScreen(45, fCount + 9);
		return;
	}
	textcolor(11);
	gotoxy(47, fCount + 18);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		fCount++;
		system("cls");
		fflush(stdin);
		goto blabla;
		WriteScoreToFile("Scores.csv", scores);
	}
	WriteScoreToFile("Scores.csv", scores);
}

void ViewScore(User& current, vector<Course>& courses, vector<Score>& scores) {
	smScreen();
	ViewListCourses(courses, "ALL");
	fCount = 15 + courses.size();
	bool Check = true;
	for (int i = 0; i < courses.size(); ++i) {
		if (current.Username == courses[i].LecturerUsername) {
			Check = false;
			break;
		}
		else Check = true;
	}
	if (!Check) {
		gotoxy(45, fCount + 1); textcolor(11);
		cout << "Enter course ID: ";
		string id;
		textcolor(8);
		getline(cin, id);
		bool isOK = true;
		for (int i = 0; i < scores.size(); ++i) {
			if (id == scores[i].CourseID) {
				isOK = false;
				break;
			}
		}
		std::cout << std::endl;
		textcolor(14);
		if (!isOK) {
			gotoxy(40, fCount + 3); cout << "    Year   | Sem |    ID    | Mid | Lab | Final | Total " << endl;
			gotoxy(40, fCount + 4); cout << "-----------+-----+----------+-----+-----+-------+-------" << endl;

			for (int i = 0; i < scores.size(); ++i) {
				if (id == scores[i].CourseID) {
					gotoxy(40, fCount + 5);
					cout << setw(10) << scores[i].Year << " |";
					cout << setw(3) << scores[i].Semester << "  |";
					cout << setw(9) << scores[i].StudentID << " |";
					cout << setw(4) << scores[i].MidScore << " |";
					cout << setw(4) << scores[i].LabScore << " |";
					cout << setw(4) << scores[i].FinalScore << "   |";
					cout << setw(4) << scores[i].TotalScore << '\n';
					fCount++;
				}
			}
		}
		else {
			gotoxy(47, fCount + 6);
			textcolor(12);
			cout << "Course not found. Please try again.";
			PauseScreen(45, fCount + 5);
			return;
		}
	}
	else
	{
		gotoxy(47, fCount + 1);
		textcolor(12); cout << "Lecturer has no course  !!!" << endl;
		PauseScreen(45, fCount + 2);
	}
}

void EditHistory(vector<History>& history, vector<Course>& courses) {
	smScreen();
	ViewListCourses(courses, "ALL");
	string ID, CoursesID, Year, temp, Class;
	int Semester, Week;

	fCount = 15 + courses.size();
	textcolor(11); gotoxy(47, fCount + 1);
	cout << "Input student ID: ";
	textcolor(8); getline(cin, ID);
	
	textcolor(11); gotoxy(47, fCount + 2);
	cout << "Input Course Code: ";
	textcolor(8);
	getline(cin, CoursesID);
	
	textcolor(11); gotoxy(47, fCount + 3);
	cout << "Input Year: ";
	textcolor(8);
	getline(cin, Year);
	
	textcolor(11); gotoxy(47, fCount + 4);
	cout << "Input Class: ";
	textcolor(8);
	getline(cin, Class);
	
	textcolor(11); gotoxy(47, fCount + 5);
	cout << "Input Semester: ";
	textcolor(8);
	getline(cin, temp);
	Semester = StringToInt(temp);
	
	textcolor(11); gotoxy(47, fCount + 6);
	cout << "Input Week: ";
	textcolor(8);
	getline(cin, temp);
	Week = StringToInt(temp);
	
	bool check = false;
	for (int i = 0; i < history.size(); i++) {
		if (history[i].CourseID == CoursesID && history[i].Year == Year && history[i].Semester == Semester &&
			history[i].Class == Class && history[i].StudentID == ID && history[i].Week == Week) {
			check = true;
			textcolor(11); gotoxy(47, fCount + 8);
			cout << "Continue to remove attendance ? (Y/N): ";
			string temp;
			getline(cin, temp);
			if (temp == "Y" || temp == "y") {
				history.erase(i);
				textcolor(14); gotoxy(50, fCount + 10);
				cout << "Remove successfully" << endl;
				WriteHistoryToFile("History.csv", history);
			}
			else {
				textcolor(12); gotoxy(50, fCount + 10);
				cout << "Operation cancelled" << endl;
			}
			PauseScreen(52, fCount + 12);
			return;
		}
	}
	if (check == false) {
		cout << "Attendance not found with given information" << endl;
		PauseScreen(52, fCount + 10);
	}
}