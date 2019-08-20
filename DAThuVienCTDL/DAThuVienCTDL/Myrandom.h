#pragma once
#pragma once
#include"Header.h"

void initRant(int a[]) {
	int index = 0;
	while (index != MAX_LIST) {
		a[index] = index;
		index++;
	}
}
void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void newRand(int a[]) {
	initRant(a);
	srand(time_t(NULL));
	int value,index = MAX_LIST-1;
	while (index != 0) {
		value = rand() % index;
		swap(a[value],a[index]);
		index--;
	};
}
//void printArr(int a[]) {
//	int i = 0;
//	while (i != MAX_LIST) {
//		cout << a[i] << "\t";
//		i++;
//	}
//}