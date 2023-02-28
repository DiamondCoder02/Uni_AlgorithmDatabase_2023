#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 15;
int numbers[N];

void generateNumbers();
void printNumbers();
void quickSort(int, int);

int main() 
{
	generateNumbers();
	printNumbers();
     
	// quickSort
	quickSort(0, N-1);
	
	printNumbers();
}

// Quickly sorting
void quickSort(int bottom, int top)
{
	int i = bottom;
	int j = top;
	int pivot = numbers[(bottom + top) / 2];
	
	do
	{
		while(numbers[i] < pivot) i++;
		while(numbers[j] > pivot) j--;
		
		if(i <= j)
		{
			swap(numbers[i], numbers[j]);
			i++;
			j--;
		}
	} while(i <= j);
	
	if(bottom < j) quickSort(bottom, j);
	if(i < top) quickSort(i, top);
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