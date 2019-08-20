#pragma once
#include"Header.h"


void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
void clreol() {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
		info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoxy(info.dwCursorPosition.X + 1, info.dwCursorPosition.Y + 1);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
char* getPwd() {
	char S[20]; int i = 0, dem = 0;
	while ((S[i] = _getch()) != ENTER)
	{
		if (wherex() >= (58+12) && wherex() <= (71+12)) {
			SetColor(CYAN);
			printf_s("%c", '*'); i++;
			SetColor(WHITE);
		}
		else {
			gotoxy((58 + 12), 16);
			SetColor(CYAN);
			printf_s("*             ");
			SetColor(WHITE);
			gotoxy((58 + 12), 16);
		}
		dem++;
		if (dem == 20) {
			gotoxy((58 + 12), 16);
			SetColor(RED);
			printf_s("Dat gioi han   ");
			SetColor(WHITE);
			_getch();
			break;
		}
	}
	S[i] = '\0';
	return S;
}

int checkPwd() {
	int dem = 0;
	for (dem = 1; dem <= 3; dem++)
	{
		gotoxy(58, 16);
		printf("Password :  ");
		if (strcmp(getPwd(), PASSWORD) == 0)   return 1;
		else {
			gotoxy(58, 16);
			SetColor(RED);
			printf_s("Password sai.Nhap lai     ");
			SetColor(WHITE);
			gotoxy(58, 16);
			_getch();
			printf_s("                          ");
		}
	}
	return 0;
}
void hienThiInterface(string link_file) {
	fstream file;
	file.open(link_file);
	if (!file) {
		SetColor(RED);
		cout << "Khong doc duoc file!!";
		SetColor(WHITE);
		_getch();
	}
	else {
		while (!file.eof()) {
			cout << (char)file.get();
		}
	}
	gotoxy(58,16);
	while (true) {
		if (checkPwd()==true) {
			gotoxy(58, 16);
			SetColor(GREEN);
			cout <<"An phim bat ky de tiep tuc!!";
			SetColor(WHITE);
			gotoxy(58, 16);
			_getch();
			break;
		}
	}
	system("cls");
	file.close();
}
void hienThiFile(string link_file) {
	fstream file;
	file.open(link_file);
	if (!file) {
		cout << "Khong doc duoc file!!";
	}
	else {
		while (!file.eof()) {
			cout << (char)file.get();
		}
	}
	file.close();
}
void xoa(char s[90], int vitrixoa)
{
	int n = strlen(s);
	for (int i = vitrixoa; i < n; i++)
		s[i] = s[i + 1];
	s[n - 1] = '\0';
}
void chuanHoaChuoi(char* s) {
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ' '&& s[i + 1] == ' ')
		{
			xoa(s, i);
			i--;
		}
	if (s[0] == ' ')
		xoa(s, 0);
	if (s[strlen(s) - 1] == ' ')
		xoa(s, strlen(s) - 1);
	s[0] = toupper(s[0]);
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ' ')
		{
			s[i + 1] = toupper(s[i + 1]);
		}
}