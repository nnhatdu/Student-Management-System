#include "staff_lecturers.h"
#include "staff_students.h"
#include "graph.h"
#include "io.h"
int eCount = 1;
void ImportLecturer(vector<User>& users)
{
	string dir;

	cout << "Enter the csv file path: ";
	getline(cin, dir, '\n');

	ifstream f;
	f.open(dir);
	if (!f.is_open())
	{
		cout << "No csv file with such path found. Please try again." << endl;
		PauseScreen(52, 3);
		return;
	}

	string  temp;
	getline(f, temp, ',');
	User lec;

	int countSuccess = 0, countFail = 0;
	while (!f.eof())
	{
		getline(f, temp, ','); //get ordinal number into tmp
		getline(f, lec.Username, ','); //get ID
		getline(f, lec.Fullname, ','); //get fullname
		getline(f, lec.EmailAddress, ','); //get email
		getline(f, lec.Phone, ','); //get phone number
		getline(f, temp, ',');
		lec.DOB = StringToDate(temp);
		getline(f, temp, '\n');
		if (temp != "")
			lec.Gender = std::stoi(temp);
		lec.Password = getHash(PASSWORD_DEFAULT);
		lec.isFirstLogin = 1;
		lec.Type = LECTURER;
		if (temp != "" && !isDuplicated(users, lec.Username)) {
			users.push_back(lec);
			countSuccess++;
		}
		else countFail++;
	}

	f.close();
	gotoxy(45, 11);
	cout << countSuccess << " new lecturers are imported." << endl;

	gotoxy(46, 11);
	cout << countFail << " failed." << endl;
	WriteLecturerToFile("Lecturers.csv", users);
	PauseScreen(52, 24);
}

void AddLecturer(vector<User>& users)
{
blabla:
	User lec;
	string temp;
	smScreen();

	eCount = 13;
	gotoxy(45, eCount); textcolor(11); cout << "Input lecturer username: ";
	textcolor(8); getline(cin, lec.Username);
	WriteLecturerToFile("Lecturers.csv", users);

	gotoxy(45, eCount + 1); textcolor(11); cout << "Input lecturer fullname: ";
	textcolor(8); getline(cin, lec.Fullname);
	lec.EmailAddress = lec.Username + "@fit.hcmus.edu.vn";
	WriteLecturerToFile("Lecturers.csv", users);

	gotoxy(45, eCount + 2); textcolor(11); cout << "Input gender(0: Male; 1: Female): ";
	textcolor(8); getline(cin, temp);
	if (temp != "")
		lec.Gender = std::stoi(temp);
	WriteLecturerToFile("Lecturers.csv", users);

	gotoxy(45, eCount + 3); textcolor(11); cout << "Input mobile phone: ";
	textcolor(8); getline(cin, lec.Phone);
	WriteLecturerToFile("Lecturers.csv", users);

	gotoxy(45, eCount + 4); textcolor(11); cout << "Input date of birth(dd/mm/yyyy): ";
	textcolor(8); getline(cin, temp);
	WriteLecturerToFile("Lecturers.csv", users);

	lec.DOB = StringToDate(temp);
	lec.Password = getHash(PASSWORD_DEFAULT);
	lec.Type = LECTURER;
	lec.isFirstLogin = 1;

	if (!isDuplicated(users, lec.Username)) {
		users.push_back(lec);
		WriteLecturerToFile("Lecturers.csv", users);

		gotoxy(45, eCount + 6); textcolor(11); cout << "Successfully added" << endl;
	}

	else {
		gotoxy(45, eCount + 6); textcolor(11); cout << "Username is duplicated" << endl;
		PauseScreen(52, eCount + 8);
		return;
	}

	textcolor(11);
	gotoxy(45, eCount + 8);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		eCount++;
		system("cls");
		fflush(stdin);
		goto blabla;
		WriteLecturerToFile("Lecturers.csv", users);
	}
	WriteLecturerToFile("Lecturers.csv", users);
}

void EditLecturer(vector<User>& users)
{
blabla:
	string option;
	string ID, Fullname, Email, Phone, Password, DOB, Gender;

	ViewListLecturer(users);
	textcolor(11); gotoxy(40, eCount + 2);
	cout << "Input lecturer username: ";
	textcolor(8); getline(cin, ID);

	bool check = false;
	int i;
	int count = 1;
	for (i = 0; i < users.size(); ++i)
	{
		if (users[i].Username == ID && users[i].Type == LECTURER)
		{
			check = true;
			break;
		}
	}

	if (check)
	{
		textcolor(14);
		gotoxy(50, eCount + 4); cout << "1. Change full name";
		gotoxy(50, eCount + 5); cout << "2. Change email";
		gotoxy(50, eCount + 6); cout << "3. Change mobile phone";
		gotoxy(50, eCount + 7); cout << "4. Change gender";
		gotoxy(50, eCount + 8); cout << "5. Change day of birth";
		gotoxy(50, eCount + 9); cout << "6. Reset password";
		gotoxy(50, eCount + 11); cout << "Choose your option (1-6):";

		textcolor(8); getline(cin, option);

		if (option == "1")
		{
			textcolor(11);
			gotoxy(50, eCount + 13); cout << "Input new full name: ";
			textcolor(8); getline(cin, Fullname);
			users[i].Fullname = Fullname;
			WriteLecturerToFile("Lecturers.csv", users);

			textcolor(14);
			gotoxy(54, eCount + 15);
			cout << "Changed successfully" << endl;
		}

		else if (option == "2")
		{
			textcolor(11);
			gotoxy(50, eCount + 13); cout << "Input new mail: ";
			textcolor(8); getline(cin, Email);
			users[i].EmailAddress = Email;
			WriteLecturerToFile("Lecturers.csv", users);

			textcolor(14);
			gotoxy(54, eCount + 15); cout << "Changed Successfully" << endl;
		}

		else if (option == "3")
		{
			textcolor(14);
			gotoxy(50, eCount + 13); cout << "Input mobile phone: ";
			textcolor(8); getline(cin, Phone);
			users[i].Phone = Phone;
			WriteLecturerToFile("Lecturers.csv", users);

			textcolor(14);
			gotoxy(54, eCount + 15); cout << "Changed Successfully" << endl;
		}

		else if (option == "4")
		{
			textcolor(11);
			gotoxy(50, eCount + 13); cout << "Input gender(0: Male; 1: Female): ";
			textcolor(8); getline(cin, Gender);
			if (!Gender.empty()) {
				users[i].Gender = std::stoi(Gender);
				WriteLecturerToFile("Lecturers.csv", users);

				textcolor(14);
				gotoxy(54, eCount + 15); cout << "Changed Successfully" << endl;
			}
			else { textcolor(12); gotoxy(49, eCount + 15); cout << "Gender cannot be empty. Please try again" << endl; }
		}

		else if (option == "5")
		{
			textcolor(11);
			gotoxy(50, eCount + 13); cout << "Input new day of birth: ";
			string temp;
			textcolor(8); getline(cin, temp);
			users[i].DOB = StringToDate(temp);
			WriteLecturerToFile("Lecturers.csv", users);

			textcolor(14);
			gotoxy(54, eCount + 15);
			cout << "Changed successfully" << endl;
		}

		else if (option == "6")
		{
			textcolor(11);
			gotoxy(50, eCount + 13); cout << "Continue to reset password ? (Y/N): ";
			string temp;
			textcolor(8); getline(cin, temp);
			if (temp == "Y" || temp == "y") {
				users[i].Password = getHash(PASSWORD_DEFAULT);
				users[i].isFirstLogin = 1;
				WriteLecturerToFile("Lecturers.csv", users);

				textcolor(14);
				gotoxy(54, eCount + 15);
				cout << "Password reset successfully" << endl;
			}
			else textcolor(12); gotoxy(54, eCount + 15); cout << "Password reset cancelled" << endl;
		}

		else {
			textcolor(12);
			gotoxy(42, eCount + 13); cout << "Entered action is invalid. Please try again." << endl;
		}
	}
	else {
		textcolor(12);
		gotoxy(47, eCount + 4);
		cout << "Cannot find lecturer with given ID" << endl;
		PauseScreen(45, eCount + 6);
		return;
	}

	textcolor(11);
	gotoxy(45, eCount + 17);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		eCount++;
		system("cls");
		fflush(stdin);
		goto blabla;
		WriteLecturerToFile("Lecturers.csv", users);
	}
	WriteLecturerToFile("Lecturers.csv", users);
}
void RemoveLecturer(vector<User>& users)
{
blabla:
	smScreen();
	ViewListLecturer(users);
	
	int check = 0;
	string ID;
	gotoxy(47, eCount + 2);
	textcolor(11); 
	cout << "Input lecturer username: ";
	textcolor(8); getline(cin, ID);
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].Type == LECTURER && users[i].Username == ID) {
			users.erase(i);
			check = 1;
			break;
		}
	}
	if (check == 0)
	{
		textcolor(12);
		gotoxy(44, eCount + 4);
		cout << "Lecturer not found with given username. Please try again." << std::endl;
	}
	else
	{
		WriteLecturerToFile("Lecturers.csv", users);
		textcolor(14);
		gotoxy(54, eCount + 4);
		cout << "Removed successfully" << endl;
	}
	
	gotoxy(50, eCount + 6);
	textcolor(11);
	cout << "Do you want to continue? (Y/N): ";
	char c = _getch();
	if (c == 'y' || c == 'Y') {
		eCount++;
		system("cls");
		fflush(stdin);
		goto blabla;
	}
	else
	{
		PauseScreen(1, eCount + 8);
		return;
	}
	WriteLecturerToFile("Lecturers.csv", users);
	PauseScreen(45, 6 + eCount);
}

void ViewListLecturer(vector<User>& users)
{
	smScreen();

	textcolor(14);
	eCount = 15;
	gotoxy(25, 13); cout << "   ID   |       Fullname     |            Email            |  Phone   |    DOB   | Gender ";
	gotoxy(25, 14); cout << "--------+--------------------+-----------------------------+----------+----------+--------";
	for (int i = 0; i < users.size(); i++) {
		if (users[i].Type == LECTURER) {
			gotoxy(25, eCount);
			cout << setw(8) << users[i].Username << "|";
			cout << setw(20) << users[i].Fullname << "|";
			cout << setw(29) << users[i].EmailAddress << "|";
			cout << setw(10) << users[i].Phone << "|";
			cout << setw(2) << users[i].DOB.Day << "/" << setw(2) << users[i].DOB.Month << "/" << setw(4) << users[i].DOB.Year << "|";
			cout << setw(4) << users[i].Gender << "  " <<'\n';
			eCount++;
		}
	}
	PauseScreen(1, eCount + 2);
}