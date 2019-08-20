#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <string>
#include <windows.h>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <dos.h>
#include <cstring>
#include <fstream>
#include <iomanip>
//#include <unistd.h>
#define TRUE 1
#define FALSE 0
#define STACKSIZE 500
#define PASSWORD ""
//define KEY
#define ESC 			27 
#define UP 				72 
#define DOWN 			80 
#define SPACE 			32 
#define BACKSPACE 		8 
#define ENTER 			13 
#define KEY_HOME        71
#define KEY_UP          72
#define KEY_PGUP        73
#define KEY_LEFT        75
#define KEY_CENTER      76
#define KEY_RIGHT       77
#define KEY_END         79
#define KEY_DOWN        80
#define KEY_PGDN        81
#define KEY_INSERT      82
#define KEY_DELETE      83
#define KEY_F1          59
#define KEY_F2          60
#define KEY_F3          61
#define KEY_F4          62
#define KEY_F5          63
#define KEY_F6          64
#define KEY_F7          65
#define KEY_F8          66
#define KEY_F9          67
#define KEY_ESC			27
#define BACK_SPACE		8
#define KEY_SPACE		32
using namespace std;
const int ZERO = 48, NINE = 73, A = 65, Z = 90, a = 97, z = 122;
const int MAX_LIST = 10000;
enum colors {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
	LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};
string data_dau_sach = "info_dau_sach.txt";
string data_danh_muc_sach = "info_danh_muc_sach.txt";
string data_interview = "menu_sign_in.txt";
string data_menu_chinh = "menu_chinh.txt";
string data_menu_chuc_nang_3 = "menu_chuc_nang_3.txt";
int mang_ma_sach[10000];
int mang_ma_the[10000];
int mang_ma_isbn[1000];
//Giao dien dung ASCII Generator