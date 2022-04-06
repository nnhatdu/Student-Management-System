#pragma once
#ifndef STANDARD_H
#define STANDARD_H
#include "Header.h"

void Login(User& current, vector<User> user, bool& isSuccess);
void ChangePassword(User& current, vector<User> user);
void Info(User& current);
#endif // !STANDARD
