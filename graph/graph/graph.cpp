#include "graph.h"

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void textcolor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void line1()
{
	char a[84] = " _      ________   _________  __  _______", b[42], c[45];
	strcpy_s(b, a);
	strcat_s(a, b);

	for (int i = 0; i < strlen(a); i++)
	{
		strncpy_s(c, a + i, 44);
		c[44] = 0;
		Sleep(200);
		textcolor(3);
		gotoxy(34, 3);
		cout << c;
		if (i == strlen(b)) i = 0;
		system("cls");

	}
}

void line2()
{
	char a[84] = "| | /| / / __/ /  / ___/ __ |/  |/  / __/", b[42], c[45];
	strcpy_s(b, a);
	strcat_s(a, b);

	for (int i = 0; i < strlen(a); i++)
	{
		strncpy_s(c, a + i, 44);
		c[44] = 0;
		Sleep(200);
		textcolor(3);
		gotoxy(34, 4);
		printf("%s",c);
		if (i == strlen(b)) i = 0;
		system("cls");

	}
}

void line3()
{
	char a[84] = "| |/ |/ / _// /__/ /__/ /_/ / /|_/ / _/  ", b[42], c[45];
	strcpy_s(b, a);
	strcat_s(a, b);

	for (int i = 0; i < strlen(a); i++)
	{
		strncpy_s(c, a + i, 44);
		c[44] = 0;
		Sleep(200);
		textcolor(3);
		gotoxy(34, 5);
		printf("%s", c);
		if (i == strlen(b)) i = 0;
		system("cls");

	}
}

void line4()
{
	char a[84] = "|__/|__/___/____/|___/|____/_/  /_/___/  ", b[42], c[45];
	strcpy_s(b, a);
	strcat_s(a, b);

	for (int i = 0; i < strlen(a); i++)
	{
		strncpy_s(c, a + i, 44);
		c[44] = 0;
		Sleep(200);
		textcolor(3);
		gotoxy(34, 6);
		printf("%s", c);
		if (i == strlen(b)) i = 0;
		system("cls");

	}
}

void line5()
{
	char a[84] = "  ", b[42], c[45];
	strcpy_s(b, a);
	strcat_s(a, b);

	for (int i = 0; i < strlen(a); i++)
	{
		strncpy_s(c, a + i, 44);
		c[44] = 0;
		Sleep(200);
		textcolor(3);
		gotoxy(34, 9);
		printf("%s", c);
		if (i == strlen(b)) i = 0;
		system("cls");
	}
}



