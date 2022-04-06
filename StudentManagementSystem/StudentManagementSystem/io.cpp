#include "io.h"
#include "Header.h"
void ReadConfig(string& year, string& semester) {
	ifstream f;
	f.open("config.txt");
	SkipBOM(f);
	if (!f.is_open())
		return;
	getline(f, year, '\n');
	getline(f, semester, '\n');
	f.close();
}
void WriteConfig(string& year, string& semester) {
	ofstream o; 
	o.open("config.txt");
	if (!o.is_open()) {
		return;
	}
	o << year << endl << semester << endl;
}
void ReadStudentFromFile(string dir, vector<User>& users) {
	ifstream f;
	f.open(dir);
	//SkipBOM(f);
	if (!f.is_open())
		return;
	string temp;
	while (!f.eof()) {
		User student;
		getline(f, student.Username, ',');
		getline(f, student.Fullname, ',');
		getline(f, student.EmailAddress, ',');
		getline(f, student.Phone, ',');
		getline(f, temp, ',');
		student.DOB = StringToDate(temp);
		getline(f, student.Password, ',');
		getline(f, student.Class, ',');
		getline(f, temp, ',');
		student.Gender = std::stoi(temp);
		getline(f, temp, '\n');
		student.isFirstLogin = std::stoi(temp);
		student.Type = STUDENT;

		if (student.Username.size()!=0)
			users.push_back(student);
	}
	f.close();
}
void ReadLecturerFromFile(string dir, vector<User>& users) {
	ifstream f;
	f.open(dir);
	//SkipBOM(f);
	if (!f.is_open())
		return;
	string temp;
	while (!f.eof()) {
		User lecturer;
		getline(f, lecturer.Username, ',');
		getline(f, lecturer.Fullname, ',');
		getline(f, lecturer.EmailAddress, ',');
		getline(f, lecturer.Phone, ',');
		getline(f, temp, ',');
		lecturer.DOB = StringToDate(temp);
		getline(f, lecturer.Password, ',');
		getline(f, temp, ',');
		lecturer.Gender = std::stoi(temp);
		getline(f, temp, '\n');
		lecturer.isFirstLogin = std::stoi(temp);
		lecturer.Type = LECTURER;

		if (lecturer.Username.size()!=0)
			users.push_back(lecturer);
	}
	f.close();
}
void ReadStaffFromFile(string dir, vector<User>& users){
	ifstream f;
	f.open(dir);
	//SkipBOM(f);
	if (!f.is_open())
		return;
	string temp;
	while (!f.eof()) {
		User staff;
		getline(f, staff.Username, ',');
		getline(f, staff.Fullname, ',');
		getline(f, staff.EmailAddress, ',');
		getline(f, staff.Phone, ',');
		getline(f, temp, ',');
		staff.DOB = StringToDate(temp);
		getline(f, staff.Password, ',');
		getline(f, temp, ',');
		staff.Gender = std::stoi(temp);
		getline(f, temp, '\n');
		staff.isFirstLogin = std::stoi(temp);
		staff.Type = STAFF;

		if (staff.Username.size() != 0)
			users.push_back(staff);
	}
	f.close();
}
void ReadCourseFromFile(string dir, vector<Course>& courses){
	ifstream f;
	f.open(dir);
	if (!f.is_open())
		return;

	string temp;
	while (!f.eof()) {
		Course course;

		getline(f, course.CourseID, ',');
		getline(f, course.Year, ',');
		getline(f, temp, ',');
		course.Semester = StringToInt(temp);
		getline(f, course.CourseName, ',');
		getline(f, course.Class, ',');
		getline(f, course.LecturerUsername, '\n');
		if (course.CourseID.size() != 0)
			courses.push_back(course);
	}
	f.close();
}
void ReadScheduleFromFile(string dir, vector<Schedule>& schedules) {
	ifstream f;
	f.open(dir);
	if (!f.is_open())
		return;

	string temp;
	while (!f.eof()) {
		Schedule schedule;

		getline(f, schedule.CourseID, ',');
		getline(f, schedule.Year, ',');
		getline(f, temp, ',');
		schedule.Semester = StringToInt(temp);
		getline(f, schedule.Class, ',');
		getline(f, temp, ',');
		schedule.DateBegin = StringToDate(temp);
		getline(f, temp, ',');
		schedule.DateEnd = StringToDate(temp);
		getline(f, temp, ',');
		schedule.TimeBegin = StringToTime(temp);
		getline(f, temp, ',');
		schedule.TimeEnd = StringToTime(temp);
		getline(f, temp, '\n');
		schedule.daysOfWeek = StringToDOW(temp);
		if (schedule.CourseID.size() != 0)
			schedules.push_back(schedule);
	}
	f.close();
}
void ReadHistoryFromFile(string dir, vector<History>& history) {
	ifstream f;
	f.open(dir);
	//SkipBOM(f);
	if (!f.is_open())
		return;
	string temp;
	while (!f.eof()) {
		History his;
		getline(f, his.CourseID, ',');
		getline(f, his.Year, ',');
		getline(f, temp, ',');
		his.Semester = StringToInt(temp);
		getline(f, his.Class, ',');
		getline(f, his.StudentID, ',');
		getline(f, temp, '\n');
		his.Week = StringToInt(temp);
		his.Check = true;
		if (his.CourseID.size() != 0)
			history.push_back(his);
	}
	f.close();
}
void ReadScoreFromFile(string dir, vector<Score>& scores) {
	ifstream f;
	f.open(dir);
	//SkipBOM(f);
	if (!f.is_open())
		return;
	string temp;
	while (!f.eof()) {
		Score score;
		getline(f, score.CourseID, ',');
		getline(f, score.Year, ',');
		getline(f, temp, ',');
		score.Semester = StringToInt(temp);
		getline(f, score.StudentID, ',');
		getline(f, temp, ',');
		score.MidScore = StringToFloat(temp);
		getline(f, temp, ',');
		score.LabScore = StringToFloat(temp);
		getline(f, temp, ',');
		score.FinalScore = StringToFloat(temp);
		getline(f, temp, '\n');
		score.TotalScore = StringToFloat(temp);
		if (score.CourseID.size() != 0)
			scores.push_back(score);
	}
	f.close();
}
void WriteStudentToFile(string dir, vector<User>& users) {
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].Type == STUDENT) {
			o << users[i].Username << ',';
			o << users[i].Fullname << ',';
			o << users[i].EmailAddress << ',';
			o << users[i].Phone << ',';
			o << DateToString(users[i].DOB)<< ',';
			o << users[i].Password << ',';
			o << users[i].Class << ',';
			o << IntToString(users[i].Gender) << ',';
			o << IntToString(users[i].isFirstLogin) << endl;
		}
	}
	o.close();
}
void WriteLecturerToFile(string dir, vector<User>& users) {
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].Type == LECTURER) {
			o << users[i].Username << ',';
			o << users[i].Fullname << ',';
			o << users[i].EmailAddress << ',';
			o << users[i].Phone << ',';
			o << DateToString(users[i].DOB) << ',';
			o << users[i].Password << ',';
			o << IntToString(users[i].Gender) << ',';
			o << IntToString(users[i].isFirstLogin) << endl;
		}
	}
	o.close();
}
void WriteStaffToFile(string dir, vector<User>& users) {
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	for (int i = 0; i < users.size(); ++i) {
		if (users[i].Type == STAFF) {
			o << users[i].Username << ',';
			o << users[i].Fullname << ',';
			o << users[i].EmailAddress << ',';
			o << users[i].Phone << ',';
			o << DateToString(users[i].DOB) << ',';
			o << users[i].Password << ',';
			o << IntToString(users[i].Gender) << ',';
			o << IntToString(users[i].isFirstLogin) << endl;
		}
	}
	o.close();
}
void WriteCourseToFile(string dir, vector<Course>& courses) {
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	for (int i = 0; i < courses.size(); i++) {
		o << courses[i].CourseID << ",";
		o << courses[i].Year << ",";
		o << courses[i].Semester << ",";
		o << courses[i].CourseName << ",";
		o << courses[i].Class << ",";
		o << courses[i].LecturerUsername << endl;
	}
	o.close();
}

void WriteScheduleToFile(string dir, vector<Schedule>& schedules) {
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	for (int i = 0; i < schedules.size(); ++i) {
		o << schedules[i].CourseID << ",";
		o << schedules[i].Year << ",";
		o << schedules[i].Semester << ",";
		o << schedules[i].Class << ",";
		o << DateToString(schedules[i].DateBegin) << ",";
		o << DateToString(schedules[i].DateEnd) << ",";
		o << TimeToString(schedules[i].TimeBegin) << ",";
		o << TimeToString(schedules[i].TimeEnd) << ",";
		o << DOWToString(schedules[i].daysOfWeek) << endl;
	}
	o.close();
}

void WriteHistoryToFile(string dir, vector<History>& history) {
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	for (int i = 0; i < history.size(); ++i) {
		o << history[i].CourseID << ",";
		o << history[i].Year << ",";
		o << history[i].Semester << ",";
		o << history[i].Class << ",";
		o << history[i].StudentID << ",";
		o << history[i].Week << endl;
	}
	o.close();
}

void WriteScoreToFile(string dir, vector<Score>& scores) {
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	o << fixed << setprecision(1);
	for (int i = 0; i < scores.size(); ++i) {
		o << scores[i].CourseID << ",";
		o << scores[i].Year << ",";
		o << scores[i].Semester << ",";
		o << scores[i].StudentID << ",";
		o << scores[i].MidScore << ",";
		o << scores[i].LabScore << ",";
		o << scores[i].FinalScore << ",";
		o << scores[i].TotalScore << "\n";
	}

	o.close();
}
void WriteFile(vector<User>& users) {
	WriteStudentToFile("Students.csv", users);
	WriteLecturerToFile("Lecturers.csv", users);
	WriteStaffToFile("Staff.csv", users);
}

void ReadStudentsOfCourse(string dir, vector<StudentOfCourse>& students)
{
	ifstream f;
	f.open(dir);
	//SkipBOM(f);
	if (!f.is_open())
		return;

	string temp;
	while (!f.eof()) {
		StudentOfCourse student;
		getline(f, student.CourseID, ',');
		getline(f, student.Year, ',');
		getline(f, temp, ',');
		student.Semester = StringToInt(temp);
		getline(f, student.CourseName, ',');
		getline(f, student.Class, ',');
		getline(f, student.LecturerUsername, ',');
		getline(f, student.Username, ',');
		getline(f, student.Fullname, '\n');
		if (student.CourseID != "")
			students.push_back(student);
	}
	f.close();
}

void WriteStudentsOfCourse(string dir, vector<StudentOfCourse>& students)
{
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	for (int i = 0; i < students.size(); i++) {
		o << students[i].CourseID << ",";
		o << students[i].Year << ",";
		o << students[i].Semester << ",";
		o << students[i].CourseName << ",";
		o << students[i].Class << ",";
		o << students[i].LecturerUsername << ",";
		o << students[i].Username << ",";
		o << students[i].Fullname << endl;
	}
	o.close();
}

void ReadConfigFromFile(string dir, vector<Config>& configs)
{
	ifstream f;
	f.open(dir);
	if (!f.is_open())
		return;

	string temp;
	while (!f.eof()) {
		Config CONFIG;

		getline(f, CONFIG.Year, ',');
		getline(f, temp, '\n');
		CONFIG.Semester = StringToInt(temp);
		if (CONFIG.Year != "")
			configs.push_back(CONFIG);
	}
	f.close();
}

void WriteConfigToFile(string dir, vector<Config>& configs)
{
	ofstream o;
	o.open(dir);
	if (!o.is_open())
		return;
	for (int i = 0; i < configs.size(); ++i) {
		o << configs[i].Year << ",";
		o << configs[i].Semester << endl;
	}
	o.close();
}
