#ifndef STAFF_STUDENTS_H
#define STAFF_STUDENTS_H

#include "Header.h"
#include "function.h"

void ImportStudent(vector<User>& users);
void OutputStudentToAnotherFile(string path, vector<User>& users); // de y ham nay
void AddStudent(vector<User>& users);
void EditStudent(vector<User>& users, string& ID);
void ChangeClass(vector <User>& users, vector<Course>& courses, vector<StudentOfCourse>& students, string& ID);
void ViewListClass(vector<User>& users);
void ViewListStudent(vector<User>& users);
void RemoveStudent(vector<User>& users, string& ID);
bool isDuplicated(vector<User>& users, string& id);

void AddNewStudentToCourse(vector<StudentOfCourse>& students, vector<Course>& courses, vector<User>& users);
void RemoveStudentFromCourse(vector<StudentOfCourse>& students, vector<Course>& courses, string& ID);
void MoveEditedStudentToCourse(vector<StudentOfCourse>& students, vector<User>& users, vector<Course>& courses, string& ID);
void MoveAllEditedStudentsToCourse(vector<StudentOfCourse>& students, vector<User>& users, vector<Course>& courses);

void ViewStudents(vector<User>& users, string& ID);
#endif // !STAFF_STUDENTS_H
#pragma once
