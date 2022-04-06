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
void welcomeScreen()
{
	// line 1
	textcolor(3);
	gotoxy(45, 3);
	cout << " _      ________   _________  __  _______" << endl;

	// line 2
	gotoxy(45, 4);
	cout << "| | /| / / __/ /  / ___/ __ |/  |/  / __/" << endl;
	
	// line 3
	gotoxy(45, 5);
	cout << "| |/ |/ / _// /__/ /__/ /_/ / /|_/ / _/  " << endl;
	
	// line 4
	gotoxy(45, 6);
	cout << "|__/|__/___/____/|___/|____/_/  /_/___/  " << endl;
	
	// line 5
	gotoxy(45, 7);
	cout << " " << endl;

	textcolor(7);
	gotoxy(47, 9);
	cout << "  Student Management System v0.0.1  " << endl;
	gotoxy(48, 10);
	cout << "----------------------------------" << endl;
}

void smScreen()
{
	// line 1
	textcolor(3);
	gotoxy(7, 4);
	cout << "  _________ __            .___             __       _____                                                            __   " << endl;

	// line 2
	gotoxy(7, 5);
	cout << " /   _____//  |_ __ __  __| _/____   _____/  |_    /     | _____    ____ _____    ____   ____   _____   ____   _____/  |_ " << endl;

	// line 3
	gotoxy(7, 6);
	cout << " |_____  ||   __|  |  |/ __ |/ __ | /    |   __|  /  | /  ||__  |  /    ||__  |  / ___|_/ __ | /     |_/ __ | /    |   __|" << endl;

	// line 4
	gotoxy(7, 7);
	cout << " /        ||  | |  |  / /_/ |  ___/|   |  |  |   /    Y    |/ __ ||   |  |/ __ |/ /_/  >  ___/|  Y Y  |  ___/|   |  |  |  " << endl;

	// line 5
	gotoxy(7, 8);
	cout << "/_______  /|__| |____/|____ ||___  >___|  /__|   |____|__  (____  /___|  (____  |___  / |___  >__|_|  /|___  >___|  /__|  " << endl;

	// line 6
	gotoxy(7, 9);
	cout << "        |/                 |/    |/     |/               |/     |/     |/     |/_____/      |/      |/     |/     |/      " << endl;
}
