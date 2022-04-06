#include "display.h"
#include "io.h"

void ShowHomeScreen_Guest(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student){
	
	resizeConsole(1000, 600);
	welcomeScreen;

	string option;

	textcolor(14);

	gotoxy(50, 13);
	cout << "1. Login" << endl;
	
	gotoxy(50, 14);
	cout << "0. Exit" << endl;

	textcolor(11);
	gotoxy(50, 15);
	cout << "Please enter an action (0-1): ";
	textcolor(7);
	getline(cin, option);

	if (option == "1") Login(current, users, isLogIn);
	
	else if (option == "0") currentDisplay = EXIT;
	
	else 
	{
		textcolor(12);
		gotoxy(43, 17);
		cout << "Entered action is not legit. Please try again." << endl;
		
		PauseScreen(52, 19);
	}
}

void ShowHomeScreen_User(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student)
{
	resizeConsole(1000, 600);
	system("cls");
	smScreen();
	string option;

	textcolor(14);

	gotoxy(45, 13);
	cout << "1. Show Menu" << endl;
	
	gotoxy(45, 14);
	cout << "2. View info" << endl;
	
	gotoxy(45, 15);
	cout << "3. Change password" << endl;
	
	textcolor(7);
	gotoxy(45, 16);
	cout << "0. Logout" << endl;
	
	textcolor(11);
	gotoxy(45, 17);
	cout << "Please enter an action (0-3): ";
	textcolor(7);
	getline(cin, option);
	
	if (option == "1")
	{
		system("cls");
		currentDisplay = MENU;
	}

	else if (option == "2")
	{
		system("cls");
		Info(current);
	}

	else if (option == "3")
	{
		// Change password
		system("cls");
		welcomeScreen();
		ChangePassword(current, users);
	}

	else if (option == "0") isLogIn = false;
	
	else 
	{
		textcolor(12);
		gotoxy(43, 20);
		cout << "Entered action is not legit. Please try again." << endl;

		PauseScreen(52, 22);
	}
}

void ShowMenuScreen_Lecturer(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student, string& currentSemester, vector<StudentOfCourse>& students) {
	
	resizeConsole(1000, 600);
	system("cls");
	smScreen();

	string action;

	textcolor(14);
	gotoxy(45, 13); // 28
	cout << "1. View list of courses in the current semester" << endl;

	gotoxy(45, 14); // 29
	cout << "2. View list of students of course";

	gotoxy(45, 15); // 30
	cout << "3. View attendance list of a course";

	gotoxy(45, 16); // 31
	cout << "4. Edit an attendance";

	gotoxy(45, 17); // 32
	cout << "5. Import scoreboard of a course";

	gotoxy(45, 18); // 33
	cout << "6. Edit grade of a student";

	gotoxy(45, 19); // 34
	cout << "7. View a scoreboard";

	textcolor(7);
	gotoxy(45, 20);
	cout << "0. Go back" << endl;

	textcolor(11);
	gotoxy(43, 22);
	cout << "Please enter an action (0-7): ";
	textcolor(7);
	getline(cin, action);

	textcolor(11);

	if (action == "1") // 28
	{
		system("cls");
		string cSemester = currentSemester;
		ViewListCourses(courses, cSemester);
	}

	else if (action == "2") // 29. View list of students of a course
	{
		system("cls");
		ViewStudentOfCourse(students, courses);

	}

	else if (action == "3") // 30. View attendance list of a course
	{
		system("cls");
		ViewHistory(history, courses);
	}

	else if (action == "4") // 31. Edit an attendance
	{
		system("cls");
		EditHistory(history, courses);
	}

	else if (action == "5") // 32
	{
		system("cls");
		ImportScoreCSV(scores);
	}
	
	else if (action == "6") // 33
	{
		system("cls");
		EditGrade(scores, courses, current);
	}
	
	else if (action == "7") //34
	{
		system("cls");
		ViewScore(current, courses, scores);
	}
	
	else if (action == "0") currentDisplay = HOME;
	
	else 
	{
		textcolor(12);
		gotoxy(43, 26);
		cout << "Entered action is not legit. Please try again." << endl;

		PauseScreen(52, 28);
	}
}

void ShowMenuScreen_Student(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student) {

	resizeConsole(1000, 600);
	system("cls");
	smScreen();
	string option;
	
	textcolor(14);
	
	gotoxy(49, 13); // 35
	cout << "1. Check-in" << endl;
	
	gotoxy(49, 14); // 36
	cout << "2. View check-in result" << endl;
	
	gotoxy(49, 15); //37
	cout << "3. View schedules" << endl;
	
	gotoxy(49, 16); // 38
	cout << "4. View your scores of a course" << endl;

	textcolor(7);
	gotoxy(49, 17);
	cout << "0. Go back" << endl;
	
	textcolor(11);
	gotoxy(49, 18);
	cout << "Please enter an action (0-4): ";
	textcolor(7);
	getline(cin, option);

	textcolor(14);
	if (option == "1") // 35
	{
		system("cls");
		smScreen();
		CheckIn(current, courses, history);
	}
	
	else if (option == "2") // 36
	{
		system("cls");
		smScreen();
		ViewCheckInResult(current, history);
	}

	else if (option == "3") // 37
	{
		system("cls");
		smScreen();
		ViewScheduleStudent(current, schedules);
	}

	else if (option == "4") // 38
	{
		system("cls");
		smScreen();
		ViewScore(current, scores, courses);
	}
	
	else if (option == "0") currentDisplay = HOME;
	
	else
	{
		textcolor(12);
		gotoxy(43, 20);
		cout << "Entered action is not legit. Please try again." << endl;

		PauseScreen(52, 22);
	}
}

void ShowExitScreen() 
{	
	resizeConsole(1000, 600);
	smScreen();
	textcolor(10);
	gotoxy(50, 13);
	cout << "Thanks for using the software!" << endl;
}

void ShowMenuScreen_Staff(User& current, vector<User>& users, vector<Course>& courses, vector<Schedule>& schedules, vector<History>& history, vector<Score>& scores, bool& isLogIn, Display& currentDisplay, User& student, string& currentSemester, vector<StudentOfCourse>& students, string& currentYear, vector<Config>& configs)
{
	resizeConsole(1000, 600);
	system("cls");
	smScreen();

	string option;

	// ----------- MENU ---------------

	// CLASS
	textcolor(11); gotoxy(42, 14); cout << "CLASS";

	textcolor(14);

	gotoxy(45, 15); // 6
	cout << "1. Import students of a class from a csv file" << endl;

	gotoxy(45, 16); // 7
	cout << "2. Add a new student to a class" << endl;

	gotoxy(45, 17); // 8
	cout << "3. Edit an existing student" << endl;

	gotoxy(45, 18); // 9
	cout << "4. Remove a student" << endl;

	gotoxy(45, 19); // 10
	cout << "5. Change students from class A to class B" << endl;

	gotoxy(45, 20); // 11
	cout << "6. View list of classes" << endl;

	gotoxy(45, 21); // 12
	cout << "7. View list of students in a class" << endl;


	// COURSE 
	textcolor(11); gotoxy(42, 23); cout << "COURSE";

	textcolor(14);

	gotoxy(45, 24); // 13
	cout << "8. Create / update / delete / view academic years and semesters";

	gotoxy(45, 26); // 14
	cout << "9. Import courses from a csv file" << endl;

	gotoxy(45, 27); // 15
	cout << "10. Add a new course" << endl;

	gotoxy(45, 28); // 16
	cout << "11. Edit an existing course" << endl;

	gotoxy(45, 29); // 17
	cout << "12. Remove a course" << endl;

	gotoxy(45, 30); // 18
	cout << "13. Remove a specific student from a course" << endl;

	gotoxy(45, 31); // 19
	cout << "14. Add a specific student to a course" << endl;

	gotoxy(45, 32); // 20
	cout << "15. View list of courses in the current semester" << endl;

	gotoxy(45, 33); // 21
	cout << "16. View list of students of a course";

	gotoxy(45, 34); // 22
	cout << "17. View attendance list of a course";

	gotoxy(45, 36); // 23
	cout << "18. Create / update / delete / view all lecturers." << endl;


	// SCOREBOARD
	textcolor(11); gotoxy(42, 38); cout << "SCOREBOARD";

	textcolor(14);
	gotoxy(45, 39); // 24
	cout << "19. Search and view scoreboard of a course" << endl;

	gotoxy(45, 40); // 25
	cout << "20. Export a scoreboard to a csv file" << endl;

	//  ATTENDANCE LIST
	textcolor(11); gotoxy(42, 42); cout << "ATTENDANCE LIST";

	textcolor(14);
	gotoxy(45, 43); // 26
	cout << "21. Search and view attendance list of a course" << endl;

	gotoxy(45, 44); // 27
	cout << "22. Export attendance list to a csv file" << endl;

	// END
	textcolor(7);
	gotoxy(45, 46);
	cout << "0. Go back" << endl;

	textcolor(11);
	gotoxy(43, 48);
	cout << "Please enter an action (0-22): ";
	textcolor(7);
	getline(cin, option);

	//-----------------------------------------------------------------------------


	// --------- OPTIONS ---------------

	if (option == "1") // 6. Import students of a class from a csv file
	{
		system("cls");
		ImportStudent(users);
	}

	else if (option == "2") // 7. Add a new student to a class
	{
		system("cls");
		smScreen();
		AddStudent(users);
		AddNewStudentToCourse(students, courses, users);
	}

	else if (option == "3") // 8. Edit an existing student
	{
		string ID;
		system("cls");
		smScreen();
		EditStudent(users, ID);
		MoveEditedStudentToCourse(students, users, courses, ID);
	}

	else if (option == "4") // 9. Remove a student
	{
		string ID;
		system("cls");
		smScreen();
		RemoveStudent(users, ID);
		RemoveStudentFromCourse(students, courses, ID);
	}

	else if (option == "5") // 10. Change students from class A to class B
	{
		string ID;
		system("cls");
		smScreen();
		ChangeClass(users, courses, students, ID);
	}

	else if (option == "6") // 11. View list of classes
	{
		system("cls");
		ViewListClass(users);
	}

	else if (option == "7") // 12. View list of students in a class
	{
		system("cls");
		ViewListStudent(users);
	}

	// -------------------------

	// ---- COURSE ----
	
	else if (option == "8") // 13
	{
		blabla:
		system("cls");
		smScreen();

		textcolor(14);
		gotoxy(45, 13); //13.1
		cout << "1. Create an academic year and semester" << endl;

		gotoxy(45, 14); // 13.2
		cout << "2. Update an academic year and semester" << endl;

		gotoxy(45, 15); // 13.3
		cout << "3. Remove an academic year and semester" << endl;

		gotoxy(45, 16); // 13.4
		cout << "4. View list of academic years and semesters" << endl;

		textcolor(7);
		gotoxy(45, 17);
		cout << "0. Go back" << endl;

		textcolor(11);
		gotoxy(43, 19);
		cout << "Please enter an action (0-4): ";
		textcolor(7);
		getline(cin, option);

		if (option == "1")
		{
			system("cls");

			CreateYearSemester(configs, currentYear, currentSemester);
			goto blabla;
		}

		else if (option == "2")
		{
			system("cls");
			UpdateYearSemester(configs, currentYear, currentSemester);
			goto blabla;
		}

		else if (option == "3")
		{
			system("cls");
			RemoveYearSemester(configs, currentYear, currentSemester);
			goto blabla;
		}

		else if (option == "4")
		{
			system("cls");
			ViewYearSemester(configs);
			goto blabla;
		}

		else if (option == "0") currentDisplay = MENU;

		else
		{
			textcolor(12);
			gotoxy(43, 21);
			cout << "Entered action is not legit. Please try again." << endl;

			PauseScreen(52, 23);
			goto blabla;
		}
	}

	else if (option == "9") // 14
	{
		system("cls");
		ImportCourse(courses, students, schedules, users);
	}

	else if (option == "10") // 15
	{
		system("cls");
		AddCourse(courses, students, users);
	}

	else if (option == "11") // 16
	{
		string ID, Year, newYear, lecturerusername, newlecturer, Class, newClass;
		int Semester, newSemester;
		system("cls");
		EditCourse(courses, students, users, ID, Year, newYear, lecturerusername, newlecturer, Class, newClass, Semester, newSemester);
		//MoveStudentsToEditedCourse(students, users, courses, ID, Year, newYear, lecturerusername, newlecturer, Class, newClass, Semester, newSemester);
	}

	else if (option == "12") // 17
	{
		string ID, Year, Class, LecturerUsername;
		int Semester;
		system("cls");
		RemoveCourse(courses, students, users, ID, Year, Class, LecturerUsername, Semester);
	}

	else if (option == "13") // 18. Remove a specific student from a course
	{
		system("cls");
		RemoveAStudentFromCourse(students, courses);
	}

	else if (option == "14") // 19. Add a specific student to a course
	{
		system("cls");
		AddAStudentToCourse(students, users,courses);
	}

	else if (option == "15") // 20. View list of courses in the current semester
	{
		system("cls");
		ViewListCourses(courses, currentSemester);
	}

	else if (option == "16") // 21. View list of students of course
	{
		system("cls");
		ViewStudentOfCourse(students, courses);
	}

	else if (option == "17") // 22. View attendance list of a course
	{
		system("cls");
		ViewHistory(history, courses);
	}

	else if (option == "18") // 23. Create / update / delete / view all lecturers
	{
		ok:
		system("cls");
		smScreen();

		textcolor(14);
		gotoxy(45, 13); // 23.1
		cout << "1. Import lecturer(s) from a csv file" << endl;

		gotoxy(45, 14); // 23.2
		cout << "2. Add a lecturer" << endl;

		gotoxy(45, 15); // 23.3
		cout << "3. Edit a lecturer" << endl;

		gotoxy(45, 16); // 23.4
		cout << "4. Remove a lecturer" << endl;

		gotoxy(45, 17); // 23.5
		cout << "5. View list of lecturers" << endl;

		textcolor(7);
		gotoxy(45, 18);
		cout << "0. Go back" << endl;

		textcolor(11);
		gotoxy(43, 20);
		cout << "Please enter an action (0-22): ";
		getline(cin, option);

		if (option == "1")
		{
			system("cls");
			//ImportSchedule(courses, schedules);
			ImportLecturer(users);
			goto ok;
		}

		else if (option == "2")
		{
			system("cls");
			AddLecturer(users);
			goto ok;
		}

		else if (option == "3")
		{
			system("cls");
			EditLecturer(users);
			goto ok;
		}

		else if (option == "4")
		{
			system("cls");
			RemoveLecturer(users);
			goto ok;
		}

		else if (option == "5")
		{
			system("cls");
			ViewListLecturer(users);
			goto ok;
		}

		else if (option == "0") currentDisplay = MENU;

		else
		{
			smScreen;
			textcolor(12);
			gotoxy(43, 22);
			cout << "Entered action is not legit. Please try again." << endl;

			PauseScreen(52, 24);
			goto ok;
		}
	}

	// -------------------------------------------------------

	// ---- SCOREBOARD ----
	else if (option == "19") // 24
	{
		system("cls");
		SearchViewScore(scores, courses);
	}

	else if (option == "20") // 25
	{
		system("cls");
		ExportScore(scores);
	}

	// ----------------------------

	//  ---- ATTENDANCE LIST ----
	else if (option == "21") // 26
	{
		system("cls");
		ViewHistory(history, courses);
	}
	
	else if (option == "22") // 27
	{
		system("cls");
		ExportHistory(history);
	}
	
	// ---------------------------------------

	else if (option == "0") currentDisplay = HOME;
		
	else
	{
		textcolor(12);
		gotoxy(43, 50);
		cout << "Entered action is not legit. Please try again." << endl;

		PauseScreen(52, 52);
	}
}