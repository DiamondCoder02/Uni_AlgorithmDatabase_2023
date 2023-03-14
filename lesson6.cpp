#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int M = 100;
const int N = 15;
int numbers[N];
int result[N];

void generateNumbers();
void printNumbers(int[]);

int main() 
{
	generateNumbers();
	printNumbers(numbers);
    
	// counting sort...
    int tmp[M];
    for(int i = 0; i < M; i++) { tmp[i] = 0; }
    for(int i = 0; i < N; i++) { tmp[numbers[i]]++; }
    for(int i = 1; i < M; i++) { tmp[i] += tmp[i-1]; }
    for(int i = N-1; i >= 0; i--) {
        result[tmp[numbers[i]]-1] = numbers[i];
        tmp[numbers[i]]--;
    }
	
	printNumbers(result);
}

void generateNumbers()
{
    srand(time(NULL));
	
	for(int i = 0; i < N; i++)
	{
		numbers[i] = rand() % (M - 1) + 1;
	}
}
void printNumbers(int array[])
{
    for(int i = 0; i < N; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}