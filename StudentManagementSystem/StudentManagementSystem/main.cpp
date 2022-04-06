#include "Header.h"
#include "io.h"
#include "standard.h"
#include"display.h"
#include"function.h"
#include"graph.h"

int main()
{
	vector<User> users;
	vector<Course> courses;
	vector<Schedule> schedules;
	vector<History> history;
	vector<Score> scores;
	vector<StudentOfCourse> students;
	vector<Config> configs;
	string currentSemester;
	string currentYear;

	ReadStudentFromFile("Students.csv", users);
	ReadLecturerFromFile("Lecturers.csv", users);
	ReadStaffFromFile("Staff.csv", users);
	ReadCourseFromFile("Courses.csv", courses);
	ReadScheduleFromFile("Schedule.csv", schedules);
	ReadHistoryFromFile("History.csv", history);
	ReadScoreFromFile("Scores.csv", scores);
	ReadStudentsOfCourse("StudentsOfCourse.csv", students);
	ReadConfig(currentYear, currentSemester);
	ReadConfigFromFile("ConfigHistory.csv", configs);
	WriteStudentToFile("Backup/Students.csv", users);
	WriteLecturerToFile("Backup/Lecturers.csv", users);
	WriteStaffToFile("Backup/Staff.csv", users);
	WriteCourseToFile("Backup/Courses.csv", courses);
	WriteScheduleToFile("Backup/Schedule.csv", schedules);
	WriteHistoryToFile("Backup/History.csv", history);
	WriteScoreToFile("Backup/Scores.csv", scores);
	WriteStudentsOfCourse("Backup/StudentsOfCourse.csv", students);
	WriteConfigToFile("Backup/ConfigHistory.csv", configs);

	User current, student;
	bool isLogIn = false;
	Display currentDisplay = HOME;

	while (true)
	{
		system("CLS");

		// welcome
		welcomeScreen();

		textcolor(11);
		if (currentDisplay == EXIT) break;

		else if (currentDisplay == HOME) {
			if (isLogIn == false) ShowHomeScreen_Guest(current, users, courses, schedules, history, scores, isLogIn, currentDisplay, student);

			else if (current.isFirstLogin == true)
			{
				textcolor(12);
				gotoxy(32, 13);
				cout << "This is your first login. Please change your password to continue." << endl;

				textcolor(11);
				ChangePassword(current,users);
				for (int i = 0; i < users.size(); ++i)
				{
					if (current.Username == users[i].Username)
					{
						users[i].Password = current.Password;
						users[i].isFirstLogin = false;
						break;
					}
				}

				current.isFirstLogin = false;
				WriteFile(users);
			}

			else
			{
				ShowHomeScreen_User(current, users, courses, schedules, history, scores, isLogIn, currentDisplay, student);

				for (int i = 0; i < users.size(); ++i)
				{
					if (current.Username == users[i].Username)
					{
						users[i].Password = current.Password;
						break;
					}
				}
				WriteFile(users);
			}
		}

		else if (currentDisplay == MENU)
		{
			if (current.Type == STAFF)
			{
				ShowMenuScreen_Staff(current, users, courses, schedules, history, scores, isLogIn, currentDisplay, student, currentSemester, students, currentYear, configs);
				for (int i = 0; i < users.size(); i++) if (users[i].Username == student.Username) users[i] = student;
			}

			else if (current.Type == LECTURER) ShowMenuScreen_Lecturer(current, users, courses, schedules, history, scores, isLogIn, currentDisplay, student, currentSemester, students);

			else if (current.Type == STUDENT) ShowMenuScreen_Student(current, users, courses, schedules, history, scores, isLogIn, currentDisplay, student);
		}
	}

	WriteStudentToFile("Students.csv", users);
	WriteLecturerToFile("Lecturers.csv", users);
	WriteStaffToFile("Staff.csv", users);
	WriteCourseToFile("Courses.csv", courses);
	WriteScheduleToFile("Schedule.csv", schedules);
	WriteHistoryToFile("History.csv", history);
	WriteScoreToFile("Scores.csv", scores);
	WriteStudentsOfCourse("StudentsOfCourse.csv", students);
	WriteConfigToFile("ConfigHistory.csv", configs);

	ShowExitScreen();

	return 0;
}
