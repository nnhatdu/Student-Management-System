#include "function.h"
#include "graph.h"
bool operator<(Date& d1, Date& d2) {
	if (d1.Year < d2.Year) 
		return true;
	if (d1.Year > d2.Year) 
		return false;
	if (d1.Month < d2.Month) 
		return true;
	if (d1.Month > d2.Month) 
		return false;
	return (d1.Day < d2.Day);
}
bool operator<=(Date& d1, Date& d2) {
	if (d1.Year <= d2.Year)
		return true;
	if (d1.Year > d2.Year)
		return false;
	if (d1.Month <= d2.Month)
		return true;
	if (d1.Month > d2.Month)
		return false;
	return (d1.Day <= d2.Day);
}
bool operator>(Date& d1, Date& d2) {
	if (d1.Year > d2.Year)
		return true;
	if (d1.Year < d2.Year)
		return false;
	if (d1.Month > d2.Month)
		return true;
	if (d1.Month < d2.Month)
		return false;
	return (d1.Day > d2.Day);
}
bool operator>=(Date& d1, Date& d2) {
	if (d1.Year >= d2.Year)
		return true;
	if (d1.Year <= d2.Year)
		return false;
	if (d1.Month >= d2.Month)
		return true;
	if (d1.Month <= d2.Month)
		return false;
	return (d1.Day >= d2.Day);
}
bool  operator<(Time& t1, Time& t2) {
	if (t1.Hour < t2.Hour) 
		return true;
	if (t1.Hour > t2.Hour) 
		return false;
	return (t1.Minute < t2.Minute);
}
bool  operator>(Time& t1, Time& t2) {
	if (t1.Hour > t2.Hour)
		return true;
	if (t1.Hour < t2.Hour)
		return false;
	return (t1.Minute > t2.Minute);
}
bool operator<=(Time& t1, Time& t2) {
	if (t1.Hour <= t2.Hour) 
		return true;
	if (t1.Hour >= t2.Hour) 
		return false;
	return (t1.Minute < t2.Minute);
}
bool operator>=(Time& t1, Time& t2) {
	if (t1.Hour >= t2.Hour)
		return true;
	if (t1.Hour <= t2.Hour)
		return false;
	return (t1.Minute >= t2.Minute);
}

int StringToInt(string str) 
{
	stringstream ss(str);
	int value = 0;
	ss >> value;
	return value;
}

float StringToFloat(string str) {
	stringstream ss(str);
	float value = 0;
	ss >> value;
	return value;
}
string IntToString(int value, int d) {
	stringstream ss;
	ss << value;
	string str = ss.str();
	return str;
}
Date StringToDate(string str) 
{
	Date d;
	int p1 = str.find('/');
	int p2 = str.find('/', p1 + 1);
	d.Day = StringToInt(str.substr(0, p1));
	d.Month = StringToInt(str.substr(p1 + 1, p2 - p1 - 1));
	d.Year = StringToInt(str.substr(p2 + 1));
	return d;
}
string DateToString(Date d) {
	return IntToString(d.Day,2) + "/" + IntToString(d.Month, 2) + "/" + IntToString(d.Year, 4);
}
Time StringToTime(string str) {
	Time t;
	int pos = str.find(':');
	t.Hour = StringToInt(str.substr(0, pos));
	t.Minute = StringToInt(str.substr(pos + 1));
	return t;
}

string TimeToString(Time t) 
{
	return IntToString(t.Hour, 2) + ":" + IntToString(t.Minute, 2);
}

DaysOfWeek StringToDOW(string str) 
{
	if (str == "Monday") return MONDAY;
	
	if (str == "Tuesday") return TUESDAY;
	
	if (str == "Wednesday") return WEDNESDAY;
	
	if (str == "Thursday") return THURSDAY;
	
	if (str == "Friday") return FRIDAY;
	
	if (str == "Saturday") return SATURDAY;
	
	return SUNDAY;
}
string DOWToString(DaysOfWeek d) {
	if (d == MONDAY)
		return "Monday";
	if (d == TUESDAY)
		return "Tuesday";
	if (d == WEDNESDAY)
		return "Wednesday";
	if (d == THURSDAY)
		return "Thursday";
	if (d == FRIDAY)
		return "Friday";
	if (d == SATURDAY)
		return "Saturday";
	return "Sunday";
}

bool StringToBool(string str) 
{
	return str == "True";
}

string BoolToString(bool b) 
{
	return b ? "True" : "False";
}

void PauseScreen(int x, int y) 
{
	textcolor(9);
	gotoxy(53, y);
	cout << "Press any key to continue" << endl;
	
	_getch();
}

string getHash(string password) 
{
	SHA1 checksum;
	checksum.update(password);
	return checksum.final();
}

void SkipBOM(std::ifstream& in)
{
	char test[3] = { 0 };
	in.read(test, 3);
	if ((unsigned char)test[0] == 0xEF &&
		(unsigned char)test[1] == 0xBB &&
		(unsigned char)test[2] == 0xBF)
	{
		return;
	}
	in.seekg(0);
}