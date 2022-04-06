#include "staff_students.h"
#include "graph.h"
#include "io.h"
int dCount;
bool isDuplicated(vector<User>& users, string& id) 
{
	for (int i = 0; i < users.size(); i++) 
		if (users[i].Username == id) return true;
	return false;
}

void ImportStudent(vector<User>& users)
{
	smScreen();
	string dir;

	textcolor(11); gotoxy(40, 13);
	cout << "Enter the csv file path: ";
	textcolor(8); getline(cin, dir, '\n');
	
	ifstream f;
	f.open(dir);
	if (!f.is_open())
	{
		textcolor(12);
		gotoxy(45, 15);
		cout << "No csv file with such path found. Please try again." << endl;
		PauseScreen(52, 17);
		return;
	}
	//SkipBOM(f);
	string  temp;
	getline(f, temp, ','); 
	User stu;
	getline(f, stu.Class, '\n');
	getline(f, temp, '\n');
	int countSuccess = 0, countFail=0;
	while (!f.eof())
	{
		getline(f, temp, ','); //get ordinal number into tmp
		getline(f, stu.Username, ','); //get ID
		getline(f, stu.Fullname, ','); //get fullname
		getline(f, stu.EmailAddress, ','); //get email
		getline(f, stu.Phone, ','); //get phone number
		getline(f, temp, ',');
		stu.DOB = StringToDate(temp);
		getline(f, temp, '\n');
		if (temp != "")
			stu.Gender = std::stoi(temp);
		stu.Password = getHash(PASSWORD_DEFAULT);
		stu.isFirstLogin = 1;
		stu.Type = STUDENT;
		if (temp != "" && !isDuplicated(users, stu.Username)) {
			users.push_back(stu);
			countSuccess++;
		}
		else countFail++;
	}

	f.close();
	textcolor(14);
	gotoxy(45, 15);
	cout << countSuccess << " new students are imported." << endl;
	
	gotoxy(46, 16);
	cout << countFail << " failed." << endl;
	WriteStudentToFile("Students.csv", users);
	
	PauseScreen(52, 18);
}

void OutputStudentToAnotherFile(string path, vector<User>& users)
{
	ofstream o;
	o.open(path);
	
	if (!o.is_open())
	{
		cout << "File '" << path << "' not open" << endl;
		return;
	}

	for (int i = 0; i < users.size(); ++i) 
		o << users[i].Class << ',' << users[i].Username << ',' << users[i].Fullname << endl;
	
	o.close();
	
	WriteStudentToFile("Students.csv", users);
}

void AddStudent(vector<User>& users) 
{
blabla:
	User stu;
	string temp;

	textcolor(11), gotoxy(40, 13);
	cout << "Input class: ";
	textcolor(8); getline(cin, stu.Class);
	WriteStudentToFile("Students.csv", users);

	textcolor(11), gotoxy(40, 14); cout << "Input username: ";
	textcolor(8); getline(cin, stu.Username);
	WriteStudentToFile("Students.csv", users);

	textcolor(11), gotoxy(40, 15); cout << "Input fullname: ";
	textcolor(8); getline(cin, stu.Fullname);
	stu.EmailAddress = stu.Username + "@student.hcmus.edu.vn";
	WriteStudentToFile("Students.csv", users);

	textcolor(11), gotoxy(40, 16); cout << "Input gender(0: Male; 1: Female): ";
	textcolor(8); getline(cin, temp);
	if (temp != "")
		stu.Gender = std::stoi(temp);
	WriteStudentToFile("Students.csv", users);

	textcolor(11), gotoxy(40, 17); cout << "Input mobile phone: ";
	textcolor(8); getline(cin, stu.Phone);
	WriteStudentToFile("Students.csv", users);

	textcolor(11), gotoxy(40, 18); cout << "Input date of birth(dd/mm/yyyy): ";
	textcolor(8); getline(cin, temp);
	stu.DOB = StringToDate(temp);
	stu.Password = getHash(PASSWORD_DEFAULT);
	stu.Type = STUDENT;
	stu.isFirstLogin = 1;
	WriteStudentToFile("Students.csv", users);

	
	if (!isDuplicated(users, stu.Username)) {
		users.push_back(stu);
		WriteStudentToFile("Students.csv", users);

		textcolor(14);
		gotoxy(57, 20);
		cout << "Successfully added" << endl;
	}
	
	else {
		gotoxy(55, 20);
		textcolor(12);
		cout << "Username is duplicated" << endl;
		PauseScreen(52, 22);
		return;
	}

	textcolor(11);
	gotoxy(45, dCount + 22);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		dCount++;
		system("cls");
		fflush(stdin);
		goto blabla;
		WriteStudentToFile("Students.csv", users);
	}
	WriteLecturerToFile("Lecturers.csv", users);
}

void EditStudent(vector<User>& users, string& ID) 
{
blabla:
	string option;
	string Fullname, Email, Phone, Password, DOB, Gender;
	
	ViewStudents(users, ID);
	textcolor(11); gotoxy(40, dCount + 2);
	cout << "ID student: ";
	textcolor(8); getline(cin, ID);
	
	bool check = false;
	int i;
	for (i = 0; i < users.size(); ++i)
	{
		if (users[i].Username == ID && users[i].Type == STUDENT) 
		{
			check = true;
			break;
		}
	}

	if (check)
	{
		textcolor(14); 
		gotoxy(50, dCount + 4); cout << "1. Change full name";
		gotoxy(50, dCount + 5); cout << "2. Change email";
		gotoxy(50, dCount + 6); cout << "3. Change mobile phone";
		gotoxy(50, dCount + 7); cout << "4. Change gender";
		gotoxy(50, dCount + 8); cout << "5. Change day of birth";
		gotoxy(50, dCount + 9); cout << "6. Reset password";
		gotoxy(50, dCount + 11); cout << "Choose your option (1-6):";
		
		textcolor(8); getline(cin, option);

		if (option == "1") 
		{
			textcolor(11);
			gotoxy(50, dCount + 13); cout << "Input new full name: ";
			textcolor(8); getline(cin, Fullname);
			users[i].Fullname = Fullname;
			WriteStudentToFile("Students.csv", users);

			textcolor(14);
			gotoxy(54, dCount + 15);
			cout << "Changed successfully" << endl;
		}

		else if (option == "2") 
		{
			textcolor(11);
			gotoxy(50, dCount + 13); cout << "Input new mail: ";
			textcolor(8); getline(cin, Email);
			users[i].EmailAddress = Email;
			WriteStudentToFile("Students.csv", users);

			textcolor(14);
			gotoxy(54, dCount + 15); cout << "Changed Successfully" << endl;
		}
		
		else if (option == "3") 
		{
			textcolor(14);
			gotoxy(50, dCount + 13); cout << "Input mobile phone: ";
			textcolor(8); getline(cin, Phone);
			users[i].Phone = Phone;
			WriteStudentToFile("Students.csv", users);

			textcolor(14);
			gotoxy(54, dCount + 15); cout << "Changed Successfully" << endl;
		}
		
		else if (option == "4")
		{
			textcolor(11);
			gotoxy(50, dCount + 13); cout << "Input gender(0: Male; 1: Female): ";
			textcolor(8); getline(cin, Gender);
			if (!Gender.empty()) {
				users[i].Gender = std::stoi(Gender);
				WriteStudentToFile("Students.csv", users);

				textcolor(14);
				gotoxy(54, dCount + 15); cout << "Changed Successfully" << endl;
			}
			else { textcolor(12); gotoxy(49, dCount + 15); cout << "Gender cannot be empty. Please try again" << endl; }
		}
		
		else if (option == "5") 
		{
			textcolor(11);
			gotoxy(50, dCount + 13); cout << "Input new day of birth: ";
			string temp;
			textcolor(8); getline(cin, temp);
			users[i].DOB = StringToDate(temp);
			WriteStudentToFile("Students.csv", users);

			textcolor(14);
			gotoxy(54, dCount + 15);
			cout << "Changed successfully" << endl;
		}

		else if (option == "6")
		{
			textcolor(11);
			gotoxy(50, dCount + 13); cout << "Continue to reset password ? (Y/N): ";
			string temp;
			textcolor(8); getline(cin, temp);
			if (temp == "Y" || temp == "y") {
				users[i].Password = getHash(PASSWORD_DEFAULT);
				users[i].isFirstLogin = 1;
				WriteStudentToFile("Students.csv", users);

				textcolor(14);
				gotoxy(54, dCount + 15);
				cout << "Password reset successfully" << endl;
			}
			else textcolor(12); gotoxy(54, dCount + 15); cout << "Password reset cancelled" << endl;
		}

		else {
			textcolor(12);
			gotoxy(42, dCount + 13); cout << "Entered action is invalid. Please try again." << endl;
		}
	}
	else {
		textcolor(12);
		gotoxy(47, dCount + 4);
		cout << "Cannot find student with given ID" << endl;
		PauseScreen(45, dCount + 6);
		return;
	}
	
	textcolor(11);
	gotoxy(45, dCount + 17);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		dCount++;
		system("cls");
		fflush(stdin);
		goto blabla;
		WriteStudentToFile("Students.csv", users);
	}
	WriteStudentToFile("Students.csv", users);
}

void ChangeClass(vector <User>& users, vector<Course>& courses, vector<StudentOfCourse>& students, string& ID)
{
blabla:
	smScreen();
	int option;
	int i = 0;
	string Class;
	dCount = 15;
	textcolor(14);
	gotoxy(22, 13); cout << "    ID    |       Fullname     |             Email             |  Class  |     DOB    | Gender ";
	gotoxy(22, 14); cout << "--------+--------------------+-----------------------------+-------+----------+--------";
	for (int i = 0; i < users.size(); i++) {
		if (users[i].Type == STUDENT) {
			gotoxy(22, dCount);
			cout << setw(9) << users[i].Username << " |";
			cout << setw(20) << users[i].Fullname << "|";
			cout << setw(30) << users[i].EmailAddress << " |";
			cout << setw(8) << users[i].Class << " |";
			cout << setw(3) << users[i].DOB.Day << "/" << setw(2) << users[i].DOB.Month << "/" << setw(4) << users[i].DOB.Year << " |";
			cout << setw(4) << users[i].Gender << "  " << '\n';
			dCount++;
		}
	}
	
	gotoxy(45, dCount + 1);	cout << "1. Move all students: ";
	gotoxy(45, dCount + 2); cout << "2. Move a student: ";
	gotoxy(45, dCount + 3); cout << "0. Go back: ";
	gotoxy(45, dCount + 4); cout << "Choose your action: ";
	
	cin >> option;
	cin.ignore(100, '\n');
	
	if (option == 0) {
		textcolor(12); gotoxy(45, dCount + 6); cout << "Action cancelled." << endl;
	}
	
	else if (option == 1)
	{
		textcolor(11); gotoxy(45, dCount + 6);
		cout << "Input old class: ";
		string OldClass;
		textcolor(8); getline(cin, OldClass);
		
		textcolor(11); gotoxy(45, dCount + 7);
		cout << "Input new class: ";
		textcolor(8); getline(cin, Class);
		for (int i = 0; i < users.size(); ++i) if (users[i].Class == OldClass) users[i].Class = Class;
		WriteStudentToFile("Students.csv", users);

		textcolor(14); gotoxy(53, dCount + 9);
		cout << "Changed successfully" << endl;
		WriteStudentToFile("Students.csv", users);
		MoveAllEditedStudentsToCourse(students, users, courses);

		gotoxy(50, dCount + 11);
		textcolor(11);
		cout << "Do you want to continue? (Y/N): ";
		char c = _getch();
		if (c == 'y' || c == 'Y') {
			dCount++;
			system("cls");
			fflush(stdin);
			goto blabla;
		}
		else
		{
			PauseScreen(1, dCount + 13);
			return;
		}
	}

	else if (option == 2)
	{
		string ID;
		
		gotoxy(45, dCount + 6);
		textcolor(11);
		cout << "ID student: ";
		textcolor(8); getline(cin, ID);
		
		bool check = false;
		int i;
		
		for (i = 0; i < users.size(); ++i)
		{
			if (users[i].Username == ID && users[i].Type == STUDENT)
			{
				check = true;
				break;
			}
		}
		
		if (check) 
		{
			textcolor(11); gotoxy(45, dCount + 7); 
			cout << "Input new class: ";
			textcolor(8); getline(cin, Class);
			users[i].Class = Class;
			WriteStudentToFile("Students.csv", users);

			textcolor(14); gotoxy(53, dCount + 8); 
			cout << "Changed successfully" << endl;
			MoveEditedStudentToCourse(students, users, courses, ID);
			WriteStudentToFile("Students.csv", users);

			gotoxy(50, dCount + 11);
			textcolor(11);
			cout << "Do you want to continue? (Y/N): ";
			char c = _getch();
			if (c == 'y' || c == 'Y') {
				dCount++;
				system("cls");
				fflush(stdin);
				goto blabla;
			}
			else
			{
				PauseScreen(1, dCount + 13);
				return;
			}
		}

		else
		{
			textcolor(12); gotoxy(57, dCount + 7);
			cout << "Cannot find student with given ID" << endl;
		}
	}

	WriteStudentToFile("Students.csv", users);
}

void RemoveStudent(vector<User>& users, string& ID) {
blabla:
	ViewStudents(users, ID);
	int confirm = 0;
	
	gotoxy(47, dCount + 2);
	textcolor(11);
	cout << "Input ID: ";
	getline(cin, ID);
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].Username == ID) {
			users.erase(i);
			confirm = 1;
			break;
		}
	}
	if (confirm == 0)
	{
		textcolor(12);
		gotoxy(44, dCount + 4);
		std::cout << "Student not found with given ID. Please try again." << endl;
	}
	else
	{
		WriteStudentToFile("Students.csv", users);
		textcolor(14);
		gotoxy(54, dCount + 4);
		cout << "Removed successfully" << endl;
	}
	gotoxy(50, dCount + 6);
	textcolor(11);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		dCount++;
		system("cls");
		fflush(stdin);
		goto blabla;
	}
	else
	{
		PauseScreen(1, dCount + 8);
		return;
	}
	WriteStudentToFile("Students.csv", users);
}

void ViewListClass(vector<User>& users)
{
	int i, dCount = 13;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i].Type == STUDENT) {
			bool isDuplicate = false;
			int j;
			for (j = 0; j < i; ++j) {
				if (users[i].Class == users[j].Class) {
					isDuplicate = true;
					break;
				}
			}
			if (!isDuplicate) {
				textcolor(14);
				gotoxy(52, dCount);
				cout << "Class: " << users[i].Class << endl;
				dCount++;
			}
		}
	}
	PauseScreen(1, dCount + 2);
}

void ViewListStudent(vector<User>& users)
{
	int i, dCount = 13;
	for (i = 0; i < users.size(); i++)
	{
		if (users[i].Type == STUDENT) {
			bool isDuplicate = false;
			int j;
			for (j = 0; j < i; ++j) {
				if (users[i].Class == users[j].Class) {
					isDuplicate = true;
					break;
				}
			}
			if (!isDuplicate) {
				textcolor(14);
				gotoxy(52, dCount);
				cout << "Class: " << users[i].Class << endl;
				dCount++;
			}
		}
	}

	string Class;
	gotoxy(45, dCount + 2);
	textcolor(11);
	cout << "Input class: ";
	textcolor(8); getline(cin, Class);
	textcolor(14);
	gotoxy(22, dCount + 4); cout << "    ID    |       Fullname     |             Email             |   Phone    |     DOB    | Gender ";
	gotoxy(22, dCount + 5); cout << "----------+--------------------+-------------------------------+------------+------------+--------";
	for (int i = 0; i < users.size(); i++) {
		if (Class == users[i].Class) {
			textcolor(14);
			gotoxy(22, dCount + 6);
			cout << setw(9) << users[i].Username << " |";
			cout << setw(20) << users[i].Fullname << " |";
			cout << setw(30) << users[i].EmailAddress << " |";
			cout << setw(11) << users[i].Phone << " |";
			cout << setw(3) << users[i].DOB.Day << "/" << setw(2) << users[i].DOB.Month << "/" << setw(4) << users[i].DOB.Year << " |";
			cout << setw(4) << users[i].Gender << "  " << '\n';

			dCount++;
		}
	}
	PauseScreen(1, dCount + 8);
}

void AddNewStudentToCourse(vector<StudentOfCourse>& students, vector<Course>& courses, vector<User>& users)
{
	StudentOfCourse newStudent;
	for (int i = 0; i < courses.size(); i++) {
		newStudent.Class = users[users.size() - 1].Class;
		newStudent.Username = users[users.size() - 1].Username;
		newStudent.Fullname = users[users.size() - 1].Fullname;
		if (newStudent.Class == courses[i].Class) {
			newStudent.CourseID = courses[i].CourseID;
			newStudent.CourseName = courses[i].CourseName;
			newStudent.LecturerUsername = courses[i].LecturerUsername;
			newStudent.Semester = courses[i].Semester;
			newStudent.Year = courses[i].Year;
			students.push_back(newStudent);
		}
	}
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
}

void RemoveStudentFromCourse(vector<StudentOfCourse>& students, vector<Course>& courses, string& ID)
{
	for (int i = 0; i < courses.size(); i++) {
		for (int j = 0; j < students.size(); j++) {
			if (students[j].Username == ID) {
				students.erase(j);
				break;
			}
		}
	}
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
}

void MoveEditedStudentToCourse(vector<StudentOfCourse>& students, vector<User>& users, vector<Course>& courses, string& ID)
{
	RemoveStudentFromCourse(students, courses, ID);
	StudentOfCourse newStudent;
	for (int i = 0; i < users.size(); i++) {
		if (users[i].Type == STUDENT && users[i].Username == ID) {
			newStudent.Class = users[i].Class;
			newStudent.Username = users[i].Username;
			newStudent.Fullname = users[i].Fullname;
			for (int j = 0; j < courses.size(); j++) {
				if (newStudent.Class == courses[j].Class) {
					newStudent.CourseID = courses[j].CourseID;
					newStudent.CourseName = courses[j].CourseName;
					newStudent.LecturerUsername = courses[j].LecturerUsername;
					newStudent.Semester = courses[j].Semester;
					newStudent.Year = courses[j].Year;
					students.push_back(newStudent);
				}
			}
			break;
		}
	}
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
}

void MoveAllEditedStudentsToCourse(vector<StudentOfCourse>& students, vector<User>& users, vector<Course>& courses)
{
	for (int i = 0; i < students.size(); i++)
		students.erase(i);
	StudentOfCourse newStudent;
	for (int i = 0; i < users.size(); i++) {
		if (users[i].Type == STUDENT) {
			newStudent.Class = users[i].Class;
			newStudent.Username = users[i].Username;
			newStudent.Fullname = users[i].Fullname;
			for (int j = 0; j < courses.size(); j++) {
				if (newStudent.Class == courses[j].Class) {
					newStudent.CourseID = courses[j].CourseID;
					newStudent.CourseName = courses[j].CourseName;
					newStudent.LecturerUsername = courses[j].LecturerUsername;
					newStudent.Semester = courses[j].Semester;
					newStudent.Year = courses[j].Year;
					students.push_back(newStudent);
				}
			}
		}
	}
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
}

void ViewStudents(vector<User>& users, string& ID)
{
	smScreen();

	textcolor(14);
	dCount = 15;
	gotoxy(22, 13); cout << "    ID    |       Fullname     |             Email             |   Phone    |     DOB    | ";
	gotoxy(22, 14); cout << "----------+--------------------+-------------------------------+------------+------------+";
	for (int i = 0; i < users.size(); i++) {
		if (users[i].Type == STUDENT) {
			gotoxy(22, dCount);
			cout << setw(9) << users[i].Username << " |";
			cout << setw(20) << users[i].Fullname << " |";
			cout << setw(30) << users[i].EmailAddress << " |";
			cout << setw(11) << users[i].Phone << " |";
			cout << setw(3) << users[i].DOB.Day << "/" << setw(2) << users[i].DOB.Month << "/" << setw(4) << users[i].DOB.Year << " |";
			cout << setw(1) << users[i].Gender << '\n';
			dCount++;
		}
	}
}