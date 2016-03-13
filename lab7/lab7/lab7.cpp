// lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
void input(char*);
void count(char*, char[]);
void out(char[]);
const int SYMB_COUNT = 256;

int _tmain(int argc, _TCHAR* argv[])
{
	char list[256] = {};
	char *str;
	input(str);
	count(str, list);
	out(list);
	return 0;
}

void input(char* str){
	printf("Enter your string:\n");
	scanf(str);
}

void count(char* str, char list[]){

}

void out(char list[]){
	
}