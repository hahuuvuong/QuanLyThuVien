#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
using namespace std;
const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct Date
{
	int ngay, thang, nam;
	void dateOut() {
		cout << this->ngay <<"/"<< this->thang << "/" << this->nam;
	}
};
typedef struct Date d;

int checkYear(int nam) {
	if (nam % 400 == 0)
		return TRUE;
	if (nam % 4 == 0 && nam % 100 != 0)
		return TRUE;
	return FALSE;
}

int demNamNhuan(Date dt) {
	int N = dt.nam;
	int t = 0;
	if (checkYear(N) && dt.thang > 2)
		t++;
	if (dt.thang <= 2)
		N--;
	int i = 1900;
	for (; i < N; i++)
	{
		if (checkYear(i) == TRUE)
		{
			t++;
			goto k;
		}
	}
k:
	i += 4;
	for (; i < N; i += 4)
	{
		if (checkYear(i) == TRUE)
			t++;
	}
	return t;
}

int tinhNgay(Date n1, Date n2) {
	int t1 = (n1.nam) * 365 + n1.ngay;
	for (int i = 1; i < n1.thang; i++) {
		t1 += monthDays[i];
	}
	t1 += demNamNhuan(n1);
	int t2 = (n2.nam) * 365 + n2.ngay;
	for (int i = 1; i < n2.thang; i++)
	{
		t2 += monthDays[i];
	}
	t2 += demNamNhuan(n2);
	return t1 - t2;
}
void getTimeSystem(Date &d) {
	time_t rawtime;
	time(&rawtime);
	struct tm currTime;
	localtime_s(&currTime,&rawtime);
	d.ngay = currTime.tm_mday;
	d.thang = currTime.tm_mon + 1;
	d.nam = currTime.tm_year + 1900;
}
