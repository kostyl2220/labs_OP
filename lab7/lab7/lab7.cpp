#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
void input(char*);
void count(char*, char[]);
void out(char[]);
const int SYMB_COUNT = 65536;
const int STR_LENGTH = 100;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	char list[SYMB_COUNT] = {};
	char str[STR_LENGTH];
	input(str);
	count(str, list);
	out(list);
	system("pause");
	return 0;
}

void input(char* str){
	printf("Enter your string:\n");
	gets(str);
}

void count(char* str, char list[]){
	for (int i = 0; i < strlen(str); ++i) {
		++list[(int)str[i]+ SYMB_COUNT / 2];
	}
}

void out(char list[]){
	for (int i = 0; i < SYMB_COUNT; ++i) {
		if (list[i]) {
			printf("Count of '%c' symbol is: %d\n", i - SYMB_COUNT / 2, list[i]);
		}
	}
}