// DiamondCoder 2023.02.07
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
//On old system: setlocale(LC_ALL, "hun");


const int N = 10;
int ids[N] = { 9,10,18,23,32,41,45,60,72 };

int main() {
	int search = 45;
	int steps = 0;
	
	// Linear Searching
	int result = -1; // -1 means not found

	for (int i = 0; i < N; i++) {
		steps++;
		if (ids[i] == search) {
			result = i;
			break;
		}
		else if (ids[i] > search) {
			break;
		}
	}
	
	if (result != -1) {
		cout << "Found at " << result << ", steps taken: " << steps << endl;
	}
	else {
		cout << "Not found" << ", steps taken: " << steps << endl;
	}

	// Bi Searching
	result = -1;
	steps = 0;
	int top = N - 1;
	int bottom = 0;
	int middle;
	
	while (top >= bottom) {
		steps++;
		middle = (top + bottom) / 2;
		if (ids[middle] == search) {
			result = middle;
			break;
		}
		else if (ids[middle] < search) {
			bottom = middle + 1;
		}
		else {
			top = middle - 1;
		}
	}

	if (result != -1) {
		cout << "Found at " << result << ", steps taken: " << steps << endl;
	}
	else {
		cout << "Not found" << ", steps taken: " << steps << endl;
	}
}
