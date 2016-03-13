// lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
void input(char*);
void count(char*, char[]);
void out(char[]);
const int SYMB_COUNT = 256;

int _tmain(int argc, _TCHAR* argv[])
{
	char list[256] = {};
	char str[100];
	input(str);
	count(str, list);
	out(list);
	system("pause");
	return 0;
}

void input(char* str){
	printf("Enter your string:\n");
	cin >> str;
}

void count(char* str, char list[]){
	for (int i = 0; i < strlen(str); ++i) {
		++list[(int)str[i]];
	}
}

void out(char list[]){
	for (int i = 0; i < SYMB_COUNT; ++i) {
		if (list[i] != 0) {
			printf("Count of '%c' symbols is: %d\n", i, list[i]);
		}
	}
}