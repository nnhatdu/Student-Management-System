#ifndef LECTURER_H
#define LECTURER_H
#include "Header.h"
#include "function.h"

void ImportScoreCSV(vector<Score>& scores);
void EditGrade(vector<Score>& scores, vector <Course>& courses, User& current);
void EditHistory(vector<History>& history, vector<Course>& courses);
void ViewScore(User& current, vector<Course>& courses, vector<Score>& scores);

#endif // !LECTURER_H
