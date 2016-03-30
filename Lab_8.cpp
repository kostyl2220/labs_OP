// Lab_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

const int LINE_COUNT = 20;
const int LINE_SIZE = 100;
const char* DELIMETERS = " ";

typedef char listOfFile[LINE_COUNT][LINE_SIZE];
typedef int Characteristics[LINE_COUNT][2];
listOfFile text;

int readFromFile(listOfFile, char*);
void writeInFile(listOfFile, char*, int);
void outText(listOfFile, int);
void processLines(listOfFile, int);

int _tmain(int argc, _TCHAR* argv[])
{
	int count = readFromFile(text, "input.txt");
	printf("Start file:\n\n");
	outText(text, count);
	processLines(text, count);
	printf("\n\nEnd file:\n\n");
	outText(text, count);
	writeInFile(text, "out.txt", count);
	system("pause");
	return 0;
}

int readFromFile(listOfFile text, char* path){
	FILE* file;
	file = fopen(path, "r");
	if (!file) {
		printf("Can't read file\n");
		system("pause");
		exit(0);
	}

	int n = 0;
	while (!feof(file)) {
		fgets(text[n++], LINE_SIZE, file);
	}

	fclose(file);
	return n;
}

void outText(listOfFile text, int count) {
	for (int i = 0; i < count; ++i) {
		printf("%s", text[i]);
	}
}

void processLines(listOfFile text, int count) {
	for (int i = 0; i < count; ++i) {
		char temp[LINE_SIZE];
		strcpy_s(temp, text[i]);
		char *word = strtok(temp, DELIMETERS);
		int maxLen = 0;
		int count = 0;
		while (word) {
			++count;
			if (strlen(word) > maxLen) maxLen = strlen(word);
			word = strtok(NULL, DELIMETERS);
		}
		char cnt[LINE_SIZE];
		_itoa(count, cnt, 10);
		strcat(cnt, " ");
		strncat(cnt, text[i], strlen(text[i]) - 1);
		strcat(cnt, " ");
		char max[LINE_COUNT];
		strcat(cnt, _itoa(maxLen, max, 10));
		strcat(cnt, "\n");
		strcpy(text[i], cnt);
	}
}

void writeInFile(listOfFile text, char* path, int count) {
	FILE* out = fopen(path, "w");

	for (int i = 0; i < count; ++i) {
		fputs(text[i], out);
	}

	fclose(out);
}