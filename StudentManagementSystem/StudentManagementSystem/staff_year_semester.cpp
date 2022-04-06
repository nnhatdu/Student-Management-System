#include "staff_year_semester.h"
#include "graph.h"
#include "io.h"
int aCount = 1;
void CreateYearSemester(vector<Config>& configs, string& currentYear, string& currentSemester)
{
blabla:
	smScreen();
	Config ohyeah;
	int year1, year2, year3, year4;
	aCount = 13;
	textcolor(11); gotoxy(43, aCount);
	cout << "Input a new academic year : ";
	textcolor(8); getline(cin, ohyeah.Year);
	
	textcolor(11); gotoxy(43, aCount + 1);
	cout << "Input a new semester : ";
	string temp;
	textcolor(8); getline(cin, temp);
	ohyeah.Semester = StringToInt(temp);
	year1 = StringToInt(currentYear.substr(0, 4));
	year2 = StringToInt(ohyeah.Year.substr(0, 4));
	year3 = StringToInt(currentYear.substr(5, 4));
	year4 = StringToInt(ohyeah.Year.substr(5, 4));

	if (year2 >= year4) {
		gotoxy(40, aCount + 3); cout << "The first year cannot be less or equal to the second year. Please try again." << endl;
	}

	else if (year1 == year2 && year3 == year4) {
		if (temp == currentSemester) {
			textcolor(12);
			gotoxy(44, aCount + 3);
			std::cout << "Already the lastest academic year and semester" << endl;
			goto blabla;
		}
		else if (ohyeah.Semester < StringToInt(currentSemester)) {
			textcolor(12);
			gotoxy(40, aCount + 3);
			cout << "The new semester cannot be smaller than the current semester. Please try again." << endl;
			goto blabla;
		}
		else {
			configs.push_back(ohyeah);
			WriteConfigToFile("ConfigHistory.csv", configs);

			textcolor(14);
			gotoxy(55, aCount + 3);
			std::cout << "Create successfully";
		}
	}

	else {
		configs.push_back(ohyeah);
		WriteConfigToFile("ConfigHistory.csv", configs);

		textcolor(14);
		gotoxy(55, aCount + 3);
		std::cout << "Create successfully";
	}

	WriteConfigToFile("ConfigHistory.csv", configs);
	PauseScreen(52, aCount + 5);
}

void UpdateYearSemester(vector<Config>& configs, string& currentYear, string& currentSemester)
{
	smScreen();
	
	textcolor(14);
	gotoxy(30, 13);
	cout << "Checking for the latest academic year and semester ";
	for (int i = 0; i < 3; i++) {
		cout << ".";
		Sleep(1000);
	}
	int temp = StringToInt(currentSemester);
	if (currentYear == configs[configs.size() - 1].Year && temp == configs[configs.size() - 1].Semester) {
		gotoxy(20, 14);
		cout << "Already updated to the latest academic year and semester. Please check back again for a later time.";
		PauseScreen(52, 16);
	}
	else {
		gotoxy(45, 14);
		cout << "Update available. Confirm update ? (Y/N) ";
		string temp1;
		getline(cin, temp1);
		if (temp1 == "Y" || temp1 == "y") {
			currentYear = configs[configs.size() - 1].Year;
			currentSemester = IntToString(configs[configs.size() - 1].Semester);
			WriteConfig(currentYear, currentSemester);
			gotoxy(45, 16);
			cout << "Update successfully" << endl;
		}
		else
		{
			gotoxy(45, 16);
			cout << "Update cancelled" << endl;
		}
		PauseScreen(52, 18);
	}
}

void RemoveYearSemester(vector<Config>& configs, string& currentYear, string& currentSemester)
{
	smScreen();

	string Year, Semester;
	int confirm = 0;
	gotoxy(45, 13); textcolor(11);
	cout << "Input a new academic year : ";
	textcolor(8);
	getline(cin, Year);

	gotoxy(45, 14); textcolor(11);
	cout << "Input a new semester : ";
	textcolor(8);
	getline(cin, Semester);
	for (int i = 0; i < configs.size(); i++) {
		if (configs[i].Year == Year && configs[i].Semester == StringToInt(Semester)) {
			configs.erase(i);
			confirm = 1;
			gotoxy(55, 16); textcolor(14);
			cout << "Remove successfully";
			currentYear = configs[configs.size() - 1].Year;
			currentSemester = IntToString(configs[configs.size() - 1].Semester);
			WriteConfig(currentYear, currentSemester);
			break;
		}
	}
	if (confirm == 0) {
		gotoxy(30, 16); textcolor(12);
		cout << "Cannot found the academic year and semester with given information. Please try again.";
}
	WriteConfigToFile("ConfigHistory.csv", configs);
	PauseScreen(52, 18);
}

void ViewYearSemester(vector<Config>& configs)
{
	smScreen();
	aCount = 13;
	textcolor(14);
	gotoxy(57, aCount);
	cout << "   Year  | Sem " << endl;
	gotoxy(57, aCount + 1);
	cout << "---------+-----" << endl;
	for (int i = 0; i < configs.size(); i++) {
		gotoxy(57, aCount + 2);
		cout << setw(9) << configs[i].Year << "|";
		cout << setw(3) << configs[i].Semester << endl;
		aCount++;
	}
	PauseScreen(52, aCount + 4);
}