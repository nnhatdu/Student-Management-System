#include "function.h"
#include "standard.h"
#include "graph.h"
#include "io.h"
#include "staff_students.h"	

void Login(User& current, vector<User> user, bool& isSuccess) 
{
	textcolor(14);

	gotoxy(45, 17);
	cout << "ID: ";
	
	gotoxy(45, 18);
	cout << "Password: ";
	
	string id, password;
	
	textcolor(7);
	gotoxy(49, 17);
	getline(cin, id);
	
	gotoxy(55, 18);
	char c;
	while (true) 
	{
		c = _getch();
		
		if (c == 13) break;
		
		if (c == 8) 
		{
			if (password.size() == 0) gotoxy(55, 17);
			else cout << "\b \b";
			if (password.size() > 0)
				password.pop_back();
		}
		
		else 
		{
			password.push_back(c);
			cout << "*";
		}
	}
	
	password = getHash(password);

	for (int i = 0; i < user.size(); i++)
	{
		if (user[i].Username == id && user[i].Password == password) 
		{
			textcolor(12);
			gotoxy(55, 20);
			cout << "Lo";
			
			textcolor(14);
			gotoxy(57, 20); 
			cout << "gin ";
			
			textcolor(2);
			gotoxy(61, 20); 
			cout << "suc";
			
			textcolor(11);
			gotoxy(64, 20); 
			cout << "ces";
			
			textcolor(8);
			gotoxy(67, 20); 
			cout << "sfu";
			
			textcolor(5);
			gotoxy(70, 20); 
			cout << "lly";
			
			current = user.at(i);
			isSuccess = true;
			PauseScreen(52, 22);
			return;
		}
	}

	textcolor(12);
	gotoxy(51, 22);
	cout << "ID or password is not valid";
	isSuccess = false;
	
	PauseScreen(52, 24);
}

//void ChangePassword(User& current) 
//{
//	gotoxy(45, 21);
//	cout << "ID or password is not valid";
//	isSuccess = false;
//	zPauseScreen(45, 22);
//}

void ChangePassword(User& current, vector<User> users) {
	blabla:
	gotoxy(50, 15);
	textcolor(11);
	cout << "Enter new password: ";

	string newpassword;
	char c;

	while (true)
	{
		c = _getch();

		if (c == 13) break;

		if (c == 8)
		{
			if (newpassword.size() == 0) gotoxy(55, 34);
			else cout << "\b \b";

			if (newpassword.size() > 0) newpassword.pop_back();
		}

		else
		{
			textcolor(7);
			newpassword.push_back(c);
			cout << "*";
		}
	}
	if (newpassword == "")
	{
		textcolor(12);
		gotoxy(46, 19);
		cout << "Password cannot be empty. Try again" << endl;

		PauseScreen(52, 23);

		system("cls");
		welcomeScreen();

		goto blabla;
	}

	newpassword = getHash(newpassword);

	if (newpassword == current.Password)
	{
		textcolor(12);
		gotoxy(37, 19);
		cout << "New password is the same as current password. Try again" << endl;

		PauseScreen(52, 23);
		system("cls");
		welcomeScreen();

		goto blabla;
	}

	textcolor(11);
	gotoxy(50, 16);
	cout << "Retype password: ";

	string retype;
	while (true)
	{
		c = _getch();

		if (c == 13) break;

		if (c == 8)
		{
			if (retype.size() == 0) gotoxy(51, 34);
			else cout << "\b \b";

			if (retype.size() > 0) retype.pop_back();
		}

		else
		{
			textcolor(7);
			retype.push_back(c);
			cout << "*";
		}
	}

	if (getHash(retype) != newpassword)
	{
		textcolor(12);
		gotoxy(36, 19);
		cout << "The password you retyped is not the same as the new one !" << endl;

		PauseScreen(52, 22);
		system("cls");
		welcomeScreen();

		goto blabla;
	}

	else
	{
		current.Password = newpassword;

		textcolor(4);
		gotoxy(54, 19);
		cout << "Changed successfully" << endl;
		
		PauseScreen(52, 22);
	}
}

void Info(User& current) 
{
	system("cls");

	cout << "\n\tID: " << current.Username << endl;
	cout << "\n\tName: " << current.Fullname << endl;
	cout << "\n\tGender: " << (current.Gender == 0 ? "Male" : "Female") << endl;
	cout << "\n\tEmail address: " << current.EmailAddress << endl;
	cout << "\n\tPhone number: " << current.Phone << endl;
	cout << "\n\tDay of birth: " << DateToString(current.DOB) << endl;
	
	if (current.Type == 0) cout << "\n\tClass: " << current.Class << endl;
	
	cout << "\n\tAccount type: " << (current.Type == 0 ? "Student" : current.Type == 1 ? "Staff" : "Lecturer") << endl;
	
	PauseScreen(52, 22);
}