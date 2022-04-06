#include "staff_courses.h"
#include "graph.h"
#include "io.h"
#include <conio.h>
int bCount;
void ImportCourse(vector<Course>& courses, vector<StudentOfCourse>& students, vector<Schedule>& schedules, vector<User>& users) 
{
	resizeConsole(1000, 600);
	system("cls");
	smScreen();

	string dir;
	textcolor(11);
	gotoxy(27,13);
	cout << "Enter the path of csv file: "; 
	textcolor(8);
	getline(cin, dir, '\n');
	
	ifstream f;
	f.open(dir);
	if (!f.is_open()) 
	{
		textcolor(12);
		gotoxy(45, 18);
		cout << "Csv file cannot be found. Please try again." << endl;
		
		PauseScreen(52, 20);
		return;
	}
	int count = 0;
	string temp;
	getline(f, temp, ',');
	string Class;
	getline(f, Class, '\n');
	getline(f, temp, '\n');
	while (!f.eof()) {
		Course course;
		StudentOfCourse studentofcourse;
		Schedule sche;
		textcolor(11);
		getline(f, studentofcourse.CourseID, ',');
		course.CourseID = studentofcourse.CourseID;
		sche.CourseID = course.CourseID;
		getline(f, studentofcourse.Year, ',');
		course.Year = studentofcourse.Year;
		sche.Year = course.Year;
		getline(f, temp, ',');
		studentofcourse.Semester = StringToInt(temp);
		course.Semester = studentofcourse.Semester;
		sche.Semester = course.Semester;
		getline(f, studentofcourse.CourseName, ',');
		course.CourseName = studentofcourse.CourseName;
		
		getline(f, studentofcourse.LecturerUsername, ',');
		course.LecturerUsername = studentofcourse.LecturerUsername;
		
		getline(f, temp, ',');
		sche.DateBegin = StringToDate(temp);
		getline(f, temp, ',');
		sche.DateEnd = StringToDate(temp);
		getline(f, temp, ',');
		sche.TimeBegin = StringToTime(temp);
		getline(f, temp, ',');
		sche.TimeEnd = StringToTime(temp);
		getline(f, temp, '\n');
		sche.daysOfWeek = StringToDOW(temp);
		sche.Class = Class;
		course.Class = Class;
		studentofcourse.Class = Class;
		
		if (course.CourseID != "") {
			courses.push_back(course);
			schedules.push_back(sche);
			for (int k = 0; k < users.size(); k++) {
				if (users.at(k).Class == Class) {
					studentofcourse.Username = users[k].Username;
					studentofcourse.Fullname = users[k].Fullname;
					students.push_back(studentofcourse);
				}
			}
			count++;
		}
	}
	f.close();
	
	textcolor(14);
	gotoxy(55,18);
	cout << count << "Courses imported" << endl;
	WriteCourseToFile("Courses.csv", courses);
	WriteScheduleToFile("Schedule.csv", schedules);
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
	PauseScreen(52,20);
}

void RemoveCourse(vector<Course>& courses, vector<StudentOfCourse>& students, vector<User>& users, string& ID, string& Year, string& Class, string& LecturerUsername, int& Semester)
{
	resizeConsole(1000, 600);
	system("cls");
	smScreen();
	bCount = 0;
	textcolor(14);
	ViewListCourses(courses, "ALL");

	int count = 1;
	string temp;
	textcolor(11);
	gotoxy(30, bCount + 2);
	cout << "Input a Course code that you want to remove: "; 
	textcolor(8);
	getline(cin, ID);
	
	textcolor(11);
	gotoxy(30, bCount + 3);
	cout << "Input a year: "; 
	textcolor(8);
	getline(cin, Year);
	
	textcolor(11);
	gotoxy(30, bCount + 4);
	cout << "Input semester: "; 
	textcolor(8);
	getline(cin, temp); Semester = StringToInt(temp);
	
	textcolor(11);
	gotoxy(30, bCount + 5);
	cout << "Input class: "; 
	textcolor(8);
	getline(cin, Class);
	
	textcolor(11);
	gotoxy(30, bCount + 6);
	cout << "Input lecturer username: ";
	textcolor(8);
	getline(cin, LecturerUsername);
	
	int isDelete = 0;
	for (int i = 0; i < courses.size(); ++i)
	{
		if (courses[i].CourseID == ID && courses[i].Year == Year && courses[i].Semester == Semester && 
			courses[i].Class == Class && courses[i].LecturerUsername == LecturerUsername)
		{
			courses.erase(i);
			gotoxy(52, bCount + 8);
			textcolor(14);
			cout << "Remove course successfully" << endl;
			isDelete = 1;
			RemoveStudentsFromRemovedCourse(students, users, ID, Year, Class, LecturerUsername, Semester);
			break;
		}
	}
	if (isDelete == 0)
	{
		textcolor(12);
		gotoxy(59, bCount + 8);
		cout << "Invalid course" << endl;

		PauseScreen(52, bCount + 10);
		return;
	}

	gotoxy(50, bCount + 10);
	textcolor(11);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		count++;
		system("cls");
		fflush(stdin);
		RemoveCourse(courses, students, users, ID, Year, Class, LecturerUsername, Semester);

		if (isDelete == 0)
		{
			textcolor(12);
			gotoxy(59, bCount + 8);
			cout << "Invalid course" << endl;

			PauseScreen(52, bCount + 10);
			return;
		}
	}
	else
	{
		PauseScreen(1, bCount + 12);
		return;
	}
	WriteCourseToFile("Courses.csv", courses);
}

void AddCourse(vector<Course>& courses, vector<StudentOfCourse>& students, vector<User>& users) {
	Course newCourses;

	smScreen();

	textcolor(14);
	ViewListCourses(courses, "ALL");

	int count = 1;
	bCount = 15 + courses.size();
	textcolor(11);
	gotoxy(30, bCount + 2);
	cout << "Input course id: ";
	textcolor(8);
	getline(cin, newCourses.CourseID);

	textcolor(11);
	gotoxy(30, bCount + 3);
	cout << "Input year: ";
	textcolor(8);
	getline(cin, newCourses.Year);

	textcolor(11);
	gotoxy(30, bCount + 4);
	cout << "Input semester: ";
	textcolor(8);
	cin >> newCourses.Semester;
	cin.ignore(1);

	textcolor(11);
	gotoxy(30, bCount + 5);
	cout << "Input course name: ";
	textcolor(8);
	getline(cin, newCourses.CourseName);

	textcolor(11);
	gotoxy(30, bCount + 6);
	cout << "Input class: ";
	textcolor(8);
	getline(cin, newCourses.Class);

	textcolor(11);
	gotoxy(30, bCount + 7);
	cout << "Input lecturer username: ";
	textcolor(8);
	getline(cin, newCourses.LecturerUsername);

	WriteCourseToFile("Courses.csv", courses);

	bool isSuccess = true;
	for (int i = 0; i < courses.size(); ++i) {
		if (newCourses.CourseID == courses[i].CourseID && newCourses.LecturerUsername == courses[i].LecturerUsername &&
			newCourses.Year == courses[i].Year && newCourses.Semester == courses[i].Semester && newCourses.Class == courses[i].Class)
		{
			gotoxy(52, bCount + 9);
			textcolor(12);
			cout << "Course has already existed" << endl;
			isSuccess = false;
			break;
		}
	}
	if (isSuccess == true) {
		courses.push_back(newCourses);
		WriteCourseToFile("Courses.csv", courses);

		textcolor(14);
		gotoxy(56, bCount + 9);
		cout << "Added succesfully" << endl;
		AddStudentsToNewCourse(students, courses, users);
	}

	gotoxy(50, bCount + 11);
	textcolor(11);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		count++;
		system("cls");
		fflush(stdin);
		AddCourse(courses, students, users);

		if (isSuccess == false)
		{
			textcolor(12);
			gotoxy(59, bCount + 9);
			cout << "Course has already existed" << endl;

			PauseScreen(52, bCount + 11);
			return;
		}
	}
	else
	{
		PauseScreen(1, bCount + 13);
		return;
	}
	WriteCourseToFile("Courses.csv", courses);
}

void EditCourse(vector<Course>& courses, vector<StudentOfCourse>& students, vector<User>& users, string& ID, string& Year, string& newYear, string& lecturerusername, string& newLecturer, string& Class, string& newClass, int& OldSemester, int& NewSemester) {
	smScreen();

	textcolor(14);
	ViewListCourses(courses, "ALL");

	bCount = 15 + courses.size();
	gotoxy(30, bCount + 2);
	textcolor(11);
	cout << "Input course ID: ";
	textcolor(8);
	getline(cin, ID);
	
	gotoxy(30, bCount + 3);
	textcolor(11);
	cout << "Input year: ";
	textcolor(8);
	getline(cin, Year);
	
	gotoxy(30, bCount + 4);
	textcolor(11);
	cout << "Input semester: ";
	string temp;
	textcolor(8);
	getline(cin, temp);
	OldSemester = StringToInt(temp);
	
	textcolor(11);
	gotoxy(30, bCount + 5);
	cout << "Input class: ";
	textcolor(8);
	getline(cin, Class);
	
	textcolor(11);
	gotoxy(30, bCount + 6);
	cout << "Input lecturer username: ";
	textcolor(8);
	getline(cin, lecturerusername);

	bool Check = false;
	int i;
	int count = 1;
	string newCourseName;
	string newSemester1;
	string Option;
	for (i = 0; i < courses.size(); i++) {
		if (courses[i].CourseID == ID && courses[i].Year == Year && courses[i].Class == Class &&
			courses[i].Semester == OldSemester && courses[i].LecturerUsername == lecturerusername) {
			Check = true;
			break;
		}
	}
	if (Check) {
		textcolor(14);
		gotoxy(40, bCount + 8); cout << "1. Change year";
		gotoxy(40, bCount + 9); cout << "2. Change semester";
		gotoxy(40, bCount + 10); cout << "3. Change course name";
		gotoxy(40, bCount + 11); cout << "4. Change class";
		gotoxy(40, bCount + 12); cout << "5. Change lecturer username";
		textcolor(11); gotoxy(42, bCount + 14); cout << "Choose your option: ";
		textcolor(8); getline(cin, Option);
		
		textcolor(11);
		if (Option == "1") 
		{
			gotoxy(45, bCount + 16);
			cout << "Input new year: ";
			textcolor(8); getline(cin, newYear);
			courses[i].Year = newYear;
			WriteCourseToFile("Courses.csv", courses);
			textcolor(14); gotoxy(55, bCount + 18); cout << "Changed successfully" << endl;
		}
		else if (Option == "2") {
			gotoxy(45, bCount + 16); cout << "Input new semester: ";
			textcolor(8); getline(cin, newSemester1);
			int newSemester = StringToInt(newSemester1);
			courses[i].Semester = newSemester;
			WriteCourseToFile("Courses.csv", courses);
			textcolor(14); gotoxy(55, bCount + 18); cout << "Changed successfully" << endl;
		}
		else if (Option == "3") {
			gotoxy(45, bCount + 16); cout << "Input new course name: ";
			textcolor(8); getline(cin, newCourseName);
			courses[i].CourseName = newCourseName;
			WriteCourseToFile("Courses.csv", courses);
			textcolor(14); gotoxy(55, bCount + 18); cout << "Changed successfully" << endl;
		}
		else if (Option == "4") {
			gotoxy(45, bCount + 16); cout << "Input new class: ";
			textcolor(8); getline(cin, newClass);
			courses[i].Class = newClass;
			WriteCourseToFile("Courses.csv", courses);
			textcolor(14); gotoxy(55, bCount + 18); cout << "Changed successfully" << endl;
		}
		else if (Option == "5") {
			gotoxy(45, bCount + 16); cout << "Input new lecturer username: ";
			textcolor(8); getline(cin, newLecturer);
			courses[i].LecturerUsername = newLecturer;
			WriteCourseToFile("Courses.csv", courses);
			textcolor(14); gotoxy(55, bCount + 18); cout << "Changed successfully" << endl;
		}
	
		else {
			gotoxy(45, bCount + 16);
			textcolor(12);
			cout << "Entered action is invalid. Please try again." << endl;
		}
	}

	else {
		textcolor(12);
		gotoxy(59, bCount + 8);
		cout << "Invalid course" << endl;

		PauseScreen(52, bCount + 10);
		return;
	}

	if (newSemester1 == "") NewSemester = OldSemester;
	if (newClass == "") newClass = Class;
	if (newYear == "") newYear = Year;
	if (newLecturer == "") newLecturer = lecturerusername;
	MoveStudentsToEditedCourse(students, users, courses, ID, Year, newYear, lecturerusername, newLecturer, Class, newClass, OldSemester, NewSemester);

	gotoxy(50, bCount + 20);
	textcolor(11);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		count++;
		system("cls");
		fflush(stdin);
		EditCourse(courses, students, users, ID, Year, newYear, lecturerusername, newLecturer, Class, newClass, OldSemester, NewSemester);
	}
	else
	{
		PauseScreen(52, bCount + 22);
		return;
	}
	WriteCourseToFile("Courses.csv", courses);

	PauseScreen(45, bCount + 22);
}

void ViewListCourses(vector <Course>& courses, string currentSemester)
{
	smScreen();
	resizeConsole(1000, 600);
	bCount = 15;
	textcolor(14);
	gotoxy(30, 13); cout << "   Code   |    Year   | Sem |          Course Name         |  Class  | Lecturer " << endl;
	gotoxy(30, 14); cout << "----------+-----------+-----+------------------------------+---------+----------" << endl;
	if (currentSemester == "ALL") {
		for (int i = 0; i < courses.size(); i++) {
			gotoxy(30, bCount);
			cout << setw(9) << courses[i].CourseID << " |";
			cout << setw(10) << courses[i].Year << " |";
			cout << setw(4) << courses[i].Semester << " |";
			cout << setw(29) << courses[i].CourseName << " |";
			cout << setw(8) << courses[i].Class << " |";
			cout << setw(10) << courses[i].LecturerUsername << endl;
			bCount++;
		}
	}
	else {
		int Semester = StringToInt(currentSemester);
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i].Semester == Semester) {
				gotoxy(30, bCount);
				cout << setw(9) << courses[i].CourseID << " |";
				cout << setw(10) << courses[i].Year << " |";
				cout << setw(4) << courses[i].Semester << " |";
				cout << setw(29) << courses[i].CourseName << " |";
				cout << setw(8) << courses[i].Class << " |";
				cout << setw(10) << courses[i].LecturerUsername << endl;
				bCount++;
			}
		}
		PauseScreen(45, 1 + bCount++);
	}
}

void RemoveAStudentFromCourse(vector<StudentOfCourse>& students, vector <Course>& courses)
{
	resizeConsole(1000, 600);
	smScreen();
	textcolor(14);
	ViewListCourses(courses, "ALL");
	string ID, Year, temp, Class, lecturer, username;
	int Semester;

	bCount = 15 + courses.size();
	gotoxy(45, bCount + 2); textcolor(11); cout << "Input course code: ";
	textcolor(8); getline(cin, ID);

	textcolor(11); gotoxy(45, bCount + 3); cout << "Input year: ";
	textcolor(8); getline(cin, Year);

	textcolor(11); gotoxy(45, bCount + 4); cout << "Input semester: ";
	textcolor(8); getline(cin, temp);
	Semester = StringToInt(temp);
	
	textcolor(11); gotoxy(45, bCount + 5); cout << "Input class: ";
	textcolor(8); getline(cin, Class);

	textcolor(11); gotoxy(45, bCount + 6); cout << "Input lecturer username: ";
	textcolor(8); getline(cin, lecturer);

	bool check = false;
	for (int i = 0; i < students.size(); ++i)
	{
		if (students[i].CourseID == ID && students[i].Year == Year && students[i].Semester == Semester
			&& students[i].Class == Class && students[i].LecturerUsername == lecturer)
		{
			check = true;
			break;
		}
	}
	if (check == false) {
		textcolor(12);
		gotoxy(47, bCount + 8);
		cout << "Course not found with given information." << endl;
		PauseScreen(52, bCount + 10);
		return;
	}

	gotoxy(43, bCount + 8);
	textcolor(11);
	cout << "Input student ID to remove: ";
	textcolor(8); getline(cin, username);

	check = false;

	for (int i = 0; i < students.size(); ++i)
	{
		if (students[i].CourseID == ID && students[i].Year == Year && students[i].Semester == Semester && 
			students[i].Class == Class && students[i].LecturerUsername == lecturer && students[i].Username == username)
		{
			students.erase(i);
			check = true;
			gotoxy(46, bCount + 10);
			cout << "Removed student from course successfully" << endl;
			break;
		}
	}

	if (check == false) {
		textcolor(12); gotoxy(52, bCount + 10); cout << "Student not found in course" << endl;
	}
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
	PauseScreen(52, bCount + 12);
}

void AddAStudentToCourse(vector<StudentOfCourse>& students, vector<User>& users,vector<Course>& courses)
{
	resizeConsole(1000, 600);
	StudentOfCourse newStudentOfCourse;

blabla:
	smScreen();
	textcolor(14);
	ViewListCourses(courses, "ALL");
	int count = 1;

	textcolor(11); gotoxy(40, bCount + 2); cout << "Input course ID: ";
	textcolor(8); getline(cin, newStudentOfCourse.CourseID);
	
	textcolor(11); gotoxy(40, bCount + 3); cout << "Input year: ";
	textcolor(8); getline(cin, newStudentOfCourse.Year);
	
	textcolor(11); gotoxy(40, bCount + 4); cout << "Input semester: ";
	textcolor(8); cin >> newStudentOfCourse.Semester;
	cin.ignore(100,'\n');

	textcolor(11); gotoxy(40, bCount + 5); cout << "Input class: ";
	textcolor(8); getline(cin, newStudentOfCourse.Class);

	textcolor(11); gotoxy(40, bCount + 6); cout << "Input lecturer username: ";
	textcolor(8); getline(cin, newStudentOfCourse.LecturerUsername);

	
	bool check = false;
	for (int i = 0; i < courses.size(); ++i)
	{
		if (courses[i].CourseID == newStudentOfCourse.CourseID && courses[i].Year == newStudentOfCourse.Year &&
			courses[i].Semester == newStudentOfCourse.Semester && courses[i].Class == newStudentOfCourse.Class &&
			courses[i].LecturerUsername == newStudentOfCourse.LecturerUsername)
		{
			newStudentOfCourse.CourseName = courses[i].CourseName;
			check = true;
			break;
		} 
	}

	if (check == false) {
		textcolor(12);
		gotoxy(54, bCount + 8);
		cout << "Course cannot be found." << endl;
		
		PauseScreen(52, bCount + 10);
		return;
	}

	textcolor(11);
	gotoxy(40, bCount + 8);
	cout << "Input student ID to add: ";
	textcolor(8); getline(cin, newStudentOfCourse.Username);
	
	check = true;
	for (int j = 0; j < students.size(); j++) {
		if (newStudentOfCourse.Username == students[j].Username && students[j].CourseID == newStudentOfCourse.CourseID && 
			students[j].Year == newStudentOfCourse.Year && students[j].Semester == newStudentOfCourse.Semester && 
			students[j].Class == newStudentOfCourse.Class && students[j].LecturerUsername == newStudentOfCourse.LecturerUsername)
		{
			textcolor(12);
			gotoxy(40, bCount + 10);
			cout << "Student already in course." << endl;
			check = false;
			break;
		}
	}
	if (check == true) {
		textcolor(14);
		gotoxy(48, bCount + 10);
		for (int i = 0; i < users.size(); i++)
		{
			if (users.at(i).Username == newStudentOfCourse.Username) {
				newStudentOfCourse.Fullname = users.at(i).Fullname;
				break;
			}
		}

		students.push_back(newStudentOfCourse);
		WriteStudentsOfCourse("StudentsOfCourse.csv", students);
		cout << "Added student to course succesfully" << endl;
	}

	gotoxy(50, bCount + 12);
	textcolor(11);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		count++;
		system("cls");
		fflush(stdin);
		goto blabla;
		WriteStudentsOfCourse("StudentsOfCourse.csv", students);
	}
	else
	{
		PauseScreen(1, bCount + 14);
		return;
	}
}

void AddStudentsToNewCourse(vector<StudentOfCourse>& students, vector<Course>& courses, vector<User>& users)
{
	StudentOfCourse newStudents;
	for (int i = 0; i < users.size(); i++) {
		newStudents.Class = users[i].Class;
		newStudents.Username = users[i].Username;
		newStudents.Fullname = users[i].Fullname;
		if (newStudents.Class == courses[courses.size() - 1].Class) {
			newStudents.CourseID = courses[courses.size() - 1].CourseID;
			newStudents.CourseName = courses[courses.size() - 1].CourseName;
			newStudents.LecturerUsername = courses[courses.size() - 1].LecturerUsername;
			newStudents.Semester = courses[courses.size() - 1].Semester;
			newStudents.Year = courses[courses.size() - 1].Year;
			students.push_back(newStudents);
		}
	}
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
}

void RemoveStudentsFromRemovedCourse(vector<StudentOfCourse>& students, vector<User>& users, string& ID, string& Year, string& Class, string& LecturerUsername, int& Semester)
{
	resizeConsole(1000, 600);
	for (int i = 0; i < users.size(); i++) {
		for (int j = 0; j < students.size(); j++) {
			if (students[j].CourseID == ID && students[j].Year == Year && students[j].Class == Class &&
				students[j].LecturerUsername == LecturerUsername && students[j].Semester == Semester) {
				students.erase(j);
				break;
			}
		}
	}
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
}
void ViewStudentOfCourse(vector<StudentOfCourse>& students, vector<Course>& courses)
{
	resizeConsole(1000, 600);
	smScreen();
	textcolor(14);
	ViewListCourses(courses, "ALL");

	string ID, Year, temp, Class, lecturer;
	int Semester;
	textcolor(11); gotoxy(40, bCount + 2); cout << "Input course code: ";
	textcolor(8); getline(cin, ID);

	textcolor(11); gotoxy(40, bCount + 3); cout << "Input year: ";
	textcolor(8); getline(cin, Year);

	textcolor(11); gotoxy(40, bCount + 4); cout << "Input semester: ";
	textcolor(8); getline(cin, temp);
	Semester = StringToInt(temp);

	textcolor(11); gotoxy(40, bCount + 5); cout << "Input class: ";
	textcolor(8); getline(cin, Class);

	textcolor(11); gotoxy(40, bCount + 6); cout << "Input lecturer username: ";
	textcolor(8); getline(cin, lecturer);

	int count = 0, check = 0;
	for (int i = 0; i < courses.size(); ++i) {
		if (courses[i].CourseID == ID && courses[i].Year == Year && courses[i].Semester == Semester &&
			courses[i].LecturerUsername == lecturer && courses[i].Class == Class) {
			check = 1;
			break;
		}
	}
	if (check == 0) {
		textcolor(12);
		gotoxy(45, bCount + 8);
		cout << "Course cannot be found." << endl;
		PauseScreen(52, bCount + 10);
		return;
	}
	
	gotoxy(10, bCount + 10); cout << "   Code   |    Year   | Sem |  Class  |          Course Name         | Lecturer |    ID    |       Fullname      " << endl;
	gotoxy(10, bCount + 11); cout << "----------+-----------+-----+---------+------------------------------+----------+----------+---------------------" << endl;

	for (int i = 0; i < students.size(); ++i) {
		if (students[i].CourseID == ID && students[i].Year == Year && students[i].Semester == Semester &&
			students[i].LecturerUsername == lecturer && students[i].Class == Class) {
			textcolor(14);
			count++;
			gotoxy(10, bCount + 12 + count);
			cout << setw(9) << students[i].CourseID << " |";
			cout << setw(10) << students[i].Year << " |";
			cout << setw(3) << students[i].Semester << "  |";
			cout << setw(8) << students[i].Class << " |";
			cout << setw(29) << students[i].CourseName << " |";
			cout << setw(10) << students[i].LecturerUsername << " |";
			cout << setw(9) << students[i].Username << " |";
			cout << setw(21) << students[i].Fullname << '\n';
		}
	}
	PauseScreen(52, 28 + courses.size() + count);
}

void MoveStudentsToEditedCourse(vector<StudentOfCourse>& students, vector<User>& users, vector<Course>& courses, string& ID, string& Year, string& newYear, string& lecturerusername, string& newLecturer, string& Class, string& newClass, int& Semester, int& newSemester)
{
	RemoveStudentsFromRemovedCourse(students, users, ID, Year, Class, lecturerusername, Semester);
	StudentOfCourse newStudent;
	for (int i = 0; i < courses.size(); i++) {
		if (courses[i].Class == newClass && courses[i].CourseID == ID && courses[i].LecturerUsername == newLecturer &&
			courses[i].Semester == newSemester && courses[i].Year == newYear) {
			newStudent.Class = courses[i].Class;
			newStudent.CourseID = courses[i].CourseID;
			newStudent.CourseName = courses[i].CourseName;
			newStudent.LecturerUsername = courses[i].LecturerUsername;
			newStudent.Semester = courses[i].Semester;
			newStudent.Year = courses[i].Year;
			for (int j = 0; j < users.size(); j++) {
				if (users[j].Type == STUDENT && newStudent.Class == users[j].Class) {
					newStudent.Username = users[j].Username;
					newStudent.Fullname = users[j].Fullname;
					students.push_back(newStudent);
				}
			}
			break;
		}
	}
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
}
