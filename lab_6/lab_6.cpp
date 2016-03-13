// lab_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

<<<<<<< HEAD
void input(double&, double&);
int NSD(int, int);
bool check(double, double);

int _tmain(int argc, _TCHAR* argv[])
{
	double n, m;
	input(n, m);
	printf("NSD is %d\n", NSD((int)n, (int)m));
=======
int NSD(int, int);

int _tmain(int argc, _TCHAR* argv[])
{
	int n, m;
	printf("Enter n and m:\n");
	scanf_s("%d %d", &n, &m);
	printf("NSD is %d\n", NSD(n, m));
>>>>>>> 02ab6da10e374889f7ae0318895a0f54ecc070ba
	system("pause");
	return 0;
}

int NSD(int n, int m){
	if (n == m) return n;
	if (n == 0) return m;
	if (m == 0) return n;
	if (m == 1 || n == 1) return 1;
	if (n % 2 == 0 && m % 2 == 0) return 2 * NSD(n / 2, m / 2);
	if (n % 2 == 0 && m % 2 != 0) return NSD(n / 2, m);
	if (n % 2 != 0 && m % 2 == 0) return NSD(n, m / 2);
	return NSD(m, abs(n - m) / 2);
}
<<<<<<< HEAD

bool check(double n, double m){
	if (n < 1 || m < 1 ||
		(int)n != n || (int)m != m){
		printf("You entered wrong numbers! Try again!\n");
		return false;
	}
	return true;
}

void input(double &n, double &m) {
	printf("Enter n and m:\n");
	do {
		scanf_s("%lf %lf", &n, &m);
	} while (!check(n, m));
}
=======
>>>>>>> 02ab6da10e374889f7ae0318895a0f54ecc070ba
