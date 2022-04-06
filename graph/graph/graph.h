#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <thread>

using namespace std;

#define x_left 35
#define x_right x_left+80
#define y_top 4
#define y_bottom y_top+25
#define name_col console_x_left+30
#define id_col name_col+20
#define total_col id_col+10
#define rate_col total_cot+20
#define common_color 31
#define selected_color 46
#define bgr_color 16
#define font_color 23
#define font_not_background_of_cell_color 7
#define space_to_show_char 20

#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

typedef char str[50];

struct st
{
	string name, id, rate;
	float total;
};

typedef struct st student;

enum TRANGTHAI { DOWN, LEFT, RIGHT, ENTER, BACK, UP };

void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);

TRANGTHAI _key(int z);
void line1();
void line2();
void line3();
void line4();
void line5();

#endif
