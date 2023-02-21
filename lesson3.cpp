#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 15;
int numbers[N];

void generateNumbers();
void printNumbers();

int main() 
{
	generateNumbers();
    numbers[0] = 6;
    numbers[1] = 10;
    numbers[2] = 16;
    numbers[3] = 7;
	printNumbers();

	// insertion sort
	int actual = 0;
	int currentIndex = 0;
	for (int i = 1; i < N; i++) {
		actual = numbers[i];
		currentIndex = i;
		while (currentIndex > 0 && numbers[currentIndex - 1] > actual) {
			numbers[currentIndex] = numbers[currentIndex - 1];
			currentIndex--;
		}
		numbers[currentIndex] = actual;
	}
	
	printNumbers();
}

void generateNumbers()
{
    srand(time(NULL));
	
	for(int i = 0; i < N; i++)
	{
		numbers[i] = rand() % 99 + 1;
	}
}
void printNumbers()
{
    for(int i = 0; i < N; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}