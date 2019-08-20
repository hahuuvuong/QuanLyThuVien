#pragma once
#include"Header.h"
#include"Menudong.h"
int convertChar2Int(const char cin) {
	return (int)cin - 48;
}
char * convertString2Char(string str) {
	char *pointer_char = new char[(str.size() + 1)];
	std::copy(str.begin(), str.end(), pointer_char);
	pointer_char[str.size()] = '\0';
	return pointer_char;
}
string convertInt2String(int i) {
	int dem = 0, temp = i;
	while (temp > 0) {
		dem++;
		temp = (temp - temp % 10) / 10;
	}
	char *c = new char[dem + 1];
	char *c2 = new char[dem + 1];
	c[dem] = '\0';
	c2[dem] = '\0';
	temp = i;
	for (int i = 0; i < dem; i++) {
		c2[i] = '0';
	}
	for (int i = 0; i < dem; i++) {
		c[i] = temp % 10 + 48;
		temp = (temp - temp % 10) / 10;
	}
	for (int i = 0; i < dem; i++) {
		c2[i] = c[dem - i - 1];
	}
	free(c);
	return string(c2);
}
char * convertInt2Char(int i) {
	int dem = 0, temp = i;
	while (temp > 0) {
		dem++;
		temp = (temp - temp % 10) / 10;
	}
	char *c = new char[dem + 1];
	char *c2 = new char[dem + 1];
	c[dem] = '\0';
	c2[dem] = '\0';
	temp = i;
	for (int i = 0; i < dem; i++) {
		c2[i] = '0';
	}
	for (int i = 0; i < dem; i++) {
		c[i] = temp % 10 + 48;
		temp = (temp - temp % 10) / 10;
	}
	for (int i = 0; i < dem; i++) {
		c2[i] = c[dem - i - 1];
	}
	free(c);
	return (c2);
}
char convertLowcase2Uppercase(char c) {
	return c + (A - a);
}
char convertUppercase2Lowcase(char C) {

	return C - (A - a);
}
int	justInOneNum() {
	char temp;
	int num = 0;
	do {
		temp = _getch();
		fflush(stdin);
		if (temp >= ZERO && temp <= NINE || temp == ENTER) {
			num = num * 10 + (int)temp - 48;
		}
		else {
			cout << "Chi nhap so, moi nhap lai!!";
		}
	} while (temp != ENTER);
	return convertChar2Int(temp);
}
char * justInChar(bool const mode) {
	char character, *list1character;
	bool loop = true;
	do {
		character = _getch();
		fflush(stdin);
		if (mode) {
			if (character == ENTER || character == SPACE) {
				loop = false;
			}
		}
		if ((character >= a && character <= z) || (character >= A && character <= Z)) {
			loop = false;
		}
		else {
			cout << "Chi nhap chu cai, moi nhap lai!!";
		}
	} while (loop);
	cout << character;
	list1character = &character;
	return list1character;
}
char * justInString(bool const mode, int leng) {
	switch (mode) {
	case 0:
		cout << "\nHam chi nhap 1 ky tu abc:";
		return justInChar(0);
		break;
	case 1:/*
		cout << "\nHam nhap chuoi:";
		cout << "Nhap do dai chuoi:";
		cin >> leng;*/
		fflush(stdin);
		bool loop = true;
		char *string, temp;
		string = new char[leng];
		for (int i = 0; i < leng; i++) {
			string[i] = 0;
		}
		int i = 0;
		do {
			temp = _getch();
			fflush(stdin);
			string[i] = temp;
			cout << string[i];
			i++;
		} while (temp != ENTER && i < leng);
		return string;
		break;
	}
}

string outString(char const * listString) {
	return string(listString);
}
string uperCaseAll(string s) {
	char*c = convertString2Char(s);
	int i = 0;
	while (c[i] != '\0') {
		if (a <= c[i] && c[i] <= z) {
			c[i] = c[i] & '_';
		}
		i++;
	}
	s = string(c);
	delete[]c;
	return s;
}
void delFirstArray(char *a) {
	int i = 0;
	while (a[i] != '\0') {
		a[i] = a[i + 1];
		i++;
	}
}
void delAfterArray(char *a, int n) {
	int i = n;
	while (a[i] != '\0') {
		a[i] = a[i + 1];
		i++;
	}
}
void delLastArray(char *a) {
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}
	a[i - 1] = '\0';
}
string rightName(string s) {
	char*c = convertString2Char(s);
	int i = 0;
	while (c[i] == SPACE) {
		delFirstArray(c);
	}
	while (c[i] != '\0') {
		if (A <= c[i] && c[i] <= Z) {
			c[i] = convertUppercase2Lowcase(c[i]);
		}
		i++;
	}
	while (c[i - 1] == SPACE && c[i] == '\0') {
		delLastArray(c);
		i--;
	}
	i = 0;
	while (c[i] != '\0') {
		if (c[i - 1] == SPACE && a <= c[i] && c[i] <= z) {
			c[i] = convertLowcase2Uppercase(c[i]);
		}
		if (c[i] == SPACE && c[i + 1] == SPACE) {
			delAfterArray(c, i);
			continue;
		}
		i++;
	}
	c[0] = convertLowcase2Uppercase(c[0]);
	s = string(c);
	delete[]c;
	return s;
}
string insertName(int leng, locate x) {
	fflush(stdin);
	bool loop = true;
	char *string, temp;
	string = new char[leng];
	for (int i = 0; i < leng; i++) {
		string[i] = 0;
	}
	string[leng] = '\0';
	int i = 0;
	do {
		if (wherex() < x.cot) {
			gotoxy(x.cot, x.dong);
		}
		temp = _getch();
		fflush(stdin);
		cout << temp;
		if ((A <= temp && temp <= Z) || (a <= temp && temp <= z) || temp == SPACE || temp == ENTER || temp == BACKSPACE) {
			string[i] = temp;
			if (temp == BACKSPACE) {
				delLastArray(string);
				if(i>0) i--;
				gotoxy(wherex(),wherey());
				cout << " ";
				if (i == 0) {
					gotoxy(x.cot, x.dong);
				}else gotoxy(wherex()-1, wherey());
				continue;
			}
			i++;
			if (temp == ENTER) {
				break;
			}
		}
		else {
			gotoxy(10, 20);
			SetBGColor(RED);
			cout << "Yeu cau chi nhap ky tu ABC!!,An bat ky nut de nhap lai";
			gotoxy(x.cot, x.dong);
			_getch();
			gotoxy(10, 20);
			SetBGColor(BLACK);
			cout << "                                                      ";
			gotoxy(x.cot, x.dong);
			continue;
		}
	} while (temp != ENTER && i < leng);
	return rightName(string);
}
string insertNum_s(int leng, locate x) {
	char * temp;
	temp = new char[leng+1];
	temp[leng] = '\0';
	int i = 0;
	for (int i = 0; i < leng;) {
		if (wherex() < x.cot) {
			gotoxy(x.cot, x.dong);
		}
		temp[i] = _getch();/*
		if (i > leng-1) {
			cout << "vuot qua gioi han cho phep";
			gotoxy(x.cot + leng, x.dong);
			temp[i] = _getch();
			cout << "                          ";
			gotoxy(x.cot + leng - 1, x.dong);
			continue;
		}*/
		fflush(stdin);
		if (temp[i] >= ZERO && temp[i] <= NINE || temp[i] == ENTER || temp[i] == BACKSPACE) {
			if (temp[i] == BACKSPACE) {
				for (int j = 0; j < i-1; j++) temp[i] = '\0';
				if (i > 0) i--;
				if (i == 0) {
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(x.cot, x.dong);
				}
				else {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
				}
				continue;
			}
			cout << temp[i];
			i++;
		}
		else {
			gotoxy(x.cot,x.dong);
			SetBGColor(RED);
			cout << "Chi nhap so, moi nhap lai!!";
			gotoxy(x.cot, x.dong);
			_getch();
			gotoxy(x.cot, x.dong);
			SetBGColor(BLACK);
			cout << "                           ";
			gotoxy(x.cot, x.dong);
			for (int j = 0; j < i; j++) cout << temp[j];
			continue;
		}
	}
	return string(temp);
}
int insertNum_i(int leng, locate x) {
	char * temp;
	temp = new char[leng + 1];
	temp[leng] = '\0';
	int dem = 0;
	for (int i = 0; i < leng;) {
		if (wherex() < x.cot) {
			gotoxy(x.cot, x.dong);
		}
		temp[i] = _getch();/*
		if (i > leng-1) {
			cout << "vuot qua gioi han cho phep";
			gotoxy(x.cot + leng, x.dong);
			_getch();
			cout << "                          ";
			gotoxy(x.cot + leng - 1, x.dong);
			continue;
		}*/
		fflush(stdin);
		if (temp[i] >= ZERO && temp[i] <= NINE || temp[i] == ENTER || temp[i] == BACKSPACE) {
			if (temp[i] == BACKSPACE) {
				for (int j = 0; j < i - 1; j++) temp[i] = '\0';
				if (i > 0) i--;
				if (i == 0) {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(x.cot, x.dong);
				}
				else {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
				}
				continue;
			}else if (temp[i] == ENTER) {
				break;
			}
			else {
				cout << temp[i];
				dem = dem * 10 + int(temp[i]) - 48;
				i++;
			}
		}
		else {
			gotoxy(x.cot, x.dong);
			SetBGColor(RED);
			cout << "Chi nhap so, moi nhap lai!!";
			gotoxy(x.cot, x.dong);
			_getch();
			gotoxy(x.cot, x.dong);
			SetBGColor(BLACK);
			cout << "                           ";
			gotoxy(x.cot, x.dong);
			for (int j = 0; j < i;j++) cout << temp[j];
			continue;
		}
	}
	free(temp);
	return dem;
}