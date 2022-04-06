#ifndef STAFF_COURSES_H
#define STAFF_COURSES_H
#include "Header.h"
#include "function.h"

void ImportCourse(vector<Course>& courses, vector<StudentOfCourse>& StudentOfCourses, vector<Schedule>& schedules, vector<User>& users);
void RemoveCourse(vector<Course>& courses, vector<StudentOfCourse>& students, vector<User>& users, string& ID, string& Year, string& Class, string& LecturerUsername, int& Semester);
void AddCourse(vector<Course>& courses, vector<StudentOfCourse>& students, vector<User>& users);
void EditCourse(vector<Course>& courses, vector<StudentOfCourse>& students, vector<User>& users, string& ID, string& Year, string& newYear, string& lecturerusername, string& newLecturer, string& Class, string& newClass, int& OldSemester, int& NewSemester);
void ViewListCourses(vector<Course>& courses, string currentSemester);

void RemoveAStudentFromCourse(vector<StudentOfCourse>& students, vector <Course>& courses);
void RemoveStudentsFromRemovedCourse(vector<StudentOfCourse>& students, vector<User>& users, string& ID, string& Year, string& Class, string& LecturerUsername, int& Semester);
void AddAStudentToCourse(vector<StudentOfCourse>& students, vector<User>& users,  vector<Course>& courses);
void AddStudentsToNewCourse(vector<StudentOfCourse>& students, vector<Course>& courses, vector<User>& users);

void MoveStudentsToEditedCourse(vector<StudentOfCourse>& students, vector<User>& users, vector<Course>& courses, string& ID, string& Year, string& newYear, string& lecturerusername, string& newLecturer, string& Class, string& newClass, int& Semester, int& newSemester);

void ViewStudentOfCourse(vector<StudentOfCourse>& students, vector<Course>& courses);
#endif // STAFF_COURSE_H