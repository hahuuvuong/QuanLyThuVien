#pragma once
#include"Header.h"

void initRant(int a[]) {
	int i = 0;
	while (i != MAX_LIST) {
		a[i] = MAX_LIST;
		i++;
	}
}
int putArray(int a[], int randvalue) {
	int i = 0; bool loop = true;
	while (loop) {
		if (a[i] == MAX_LIST) {
			a[i] = randvalue;
			loop = false;
		}
		i++;
	}
	return i;
}
int testRand(int a[], int randvalue, int maxlim) {
	for (int i = 0; i < maxlim; i++) {
		if (a[i] == randvalue) {
			return 1;
		}
	}
	return 0;
}
void newRand(int a[]) {
	initRant(a);
	srand(time_t(NULL));
	int value;
	do {
		value = rand() % MAX_LIST;
		if (!testRand(a, value, MAX_LIST)) {
			value = putArray(a, value);
		}
	} while (value != MAX_LIST);
}
//void printArr(int a[]) {
//	int i = 0;
//	while (i != MAX_LIST) {
//		cout << a[i] << "\t";
//		i++;
//	}
//}