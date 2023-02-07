// DiamondCoder 2023.02.07
#include <iostream>
using namespace std;

const int N = 10;
int ids[N] = { 9, 10,18,23,32,41,45,60,72 };

int main() {
	int search = 45;
	
	// Linear Searching
	int result = -1; // -1 means not found

	for (int i = 0; i < N; i++) {
		if (ids[i] == search) {
			result = i;
			break;
		}
	}
	
	if (result != -1) {
		cout << "Found at " << result << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	// Bi Searching
	result = -1;
	int top = N - 1;
	int bottom = 0;
	int middle;
	
	while (top >= bottom) {
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
		cout << "Found at " << result << endl;
	}
	else {
		cout << "Not found" << endl;
	}
}