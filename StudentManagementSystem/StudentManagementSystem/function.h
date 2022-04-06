#include "Header.h"
#include "sha1.h"

#ifndef FUNTION_H
#define FUNTION_H
int StringToInt(string str);
float StringToFloat(string str);
string IntToString(int value, int d=0);
Date StringToDate(string str);
string DateToString(Date d);
Time StringToTime(string str);
string TimeToString(Time t);
DaysOfWeek StringToDOW(string str);
string DOWToString(DaysOfWeek d);
bool StringToBool(string str);
string BoolToString(bool b);
void PauseScreen(int x, int y);
string getHash(string password);
void SkipBOM(std::ifstream& in);
bool operator<(Date& d1, Date& d2);
bool operator>(Date& d1, Date& d2);
bool operator<=(Date& d1, Date& d2);
bool operator>=(Date& d1, Date& d2);
bool operator<(Time& t1, Time& t2);
bool operator>(Time& t1, Time& t2);
bool operator<=(Time& t1, Time& t2);
bool operator>=(Time& t1, Time& t2);

#endif