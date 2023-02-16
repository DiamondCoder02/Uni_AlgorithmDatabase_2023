// DiamondCoder 2023.02.14
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <ctime>
using namespace std;
//On old system: setlocale(LC_ALL, "hun");

const int N = 15;
int numbers[N];

void generateNumbers();
void printNumbers();

int main() {
	generateNumbers();
	printNumbers();
	// Bubble sort
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (numbers[j] > numbers[j + 1]) {
				swap(numbers[j], numbers[j + 1]);
			}
		}
	}
	printNumbers();
}

void generateNumbers()
{
	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		numbers[i] = rand() % 99 + 1;
	}
}
void printNumbers()
{
	for (int i = 0; i < N; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}