// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void input(char *mass, char *operation, int *numbers) {
	int iteratorMass = 0;
	char *strmass;

	strmass = strtok(mass, "/ ");
	numbers[iteratorMass] = atoi(strmass);

	strmass = strtok(NULL, " ");
	iteratorMass++;
	numbers[iteratorMass] = atoi(strmass);

	strmass = strtok(NULL, " ");
	*operation = *strmass;

	strmass = strtok(NULL, "/ ");
	iteratorMass++;
	numbers[iteratorMass] = atoi(strmass);

	strmass = strtok(NULL, "/+-* ");
	iteratorMass++;
	numbers[iteratorMass] = atoi(strmass);
}
int NOD(int n1, int n2)
{
	int div;
	int d;
	if (n1 == n2) {  // если числа равны, НОД найден
		return n1;
	}
	d = n1 - n2; // Находим разность чисел
	if (d < 0) {       // если разность отрицательная,
		d = -d;     // меняем знак
		div = NOD(n1, d); // вызываем функцию NOD() для двух наименьших чисел
	}
	else      // если разность n1-n2 положительная
	{
		div = NOD(n2, d); // вызываем функцию NOD() для двух наименьших чисел
	}
	return div;
}

void add(int *numbers, int *res) {
	int chislitela;
	int chislitelb;
	chislitelb = numbers[2] * numbers[1];
	chislitela = numbers[0] * numbers[3];
	res[1] = numbers[1] * numbers[3];
	res[0] = chislitela + chislitelb;
}
void sub(int *mass, int *res) {
	int chislitela;
	int chislitelb;
	res[1] = mass[1] * mass[3];
	chislitela = mass[0] * mass[3];
	chislitelb = mass[2] * mass[1];
	res[0] = chislitela - chislitelb;
}
void mydiv(int *mass, int *res) {
	res[0] = mass[0] * mass[3];
	res[1] = mass[1] * mass[2];
}
void mul(int *mass, int *res) {
	res[0] = mass[0] * mass[2];
	res[1] = mass[1] * mass[3];
}
void output(int *res) {
	int nod = 0;
	if (res[0] == res[1]) {
		printf("Result is:  1");
	}
	while (nod != 1) {
		nod = NOD(res[0], res[1]);
		res[0] /= nod;
		res[1] /= nod;
	}
	if (res[0] > res[1]) {
		int c = 0;
		while (res[0] > res[1]) {
			res[0] -= res[1];
			c++;
		}
		printf("Result is: \t %d and %d/%d", c, res[0], res[1]);
		return;
	}
	if (res[0] < res[1]) {
		printf("Result is: \t %d/%d", res[0], res[1]);
	}
}

int main()
{
	char strmass;
	int numbers[4];
	int res[2];
	char operation;
	char *buf;
	char mass[100];
	int j = 0;
	int iteratorMass = 0;
	printf("The operation must be suparated with spaces!\n");
	printf("Enter the equation: ");
	gets(mass);
	system("cls");
	printf("You entered the next equation: \n");
	printf("%s\n", mass);
	input(mass, &operation, numbers);
	iteratorMass = 0;
	switch (operation) {
	case('+'): add(numbers, res); break;
	case('-'): sub(numbers, res); break;
	case('*'): mul(numbers, res); break;
	case('/'): mydiv(numbers, res); break;
	default: printf("WrongForm");
	}
	output(res);
	_getch();
	return 0;
}
