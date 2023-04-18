#include <iostream>
using namespace std;

const int N = 9;
int graph[N][N] = {
    {0, 0, 1, 0, 1, 0, 0, 0, 0, }, //0   
    {0, 0, 1, 1, 0, 1, 0, 0, 0, }, //1
    {1, 1, 0, 0, 0, 0, 1, 1, 0, }, //2
    {0, 1, 0, 0, 0, 0, 0, 0, 0, }, //3
    {1, 0, 0, 0, 0, 0, 0, 0, 1, }, //4
    {0, 1, 0, 0, 0, 0, 0, 1, 0, }, //5
    {0, 0, 1, 0, 0, 0, 0, 0, 0, }, //6
    {0, 0, 1, 0, 0, 1, 0, 0, 0, }, //7
    {0, 0, 0, 0, 1, 0, 0, 0, 0, }  //8
//   0  1  2  3  4  5  6  7  8
};
bool check[N];
int path[N];
int pX = 0, getX = -1;
int start = 0;

void init();
void printEdges();
void printPath();

int main() 
{
    init();
    printEdges();
    
    /* BEJÁRÁS */
    //Kezdőcsúcs hozzáadása
    //Amíg vannak még hozzáadott csúcs
        //-> még fel nem derített szomszédos csúcsok keresése
        //-> ezen csúcsok hozzáadása
	
	start = 0;
	path[pX] = start;
	pX++;
	check[start] = true;

	while(pX > getX) {
		getX++;
		for (int i = 0; i < N; i++) {
			if (graph[path[getX]][i] == 1 && check[i] == false) {
				path[pX] = i;
				pX++;
				check[i] = true;
			}
		}
	}

    printPath();
}

void init()
{
    for(int i = 0; i < N; i++)
    {
        check[i] = false;
    }
}
void printEdges()
{
    cout << "Edges:" << endl;
    for(int i = 0; i < N; i++)
    {
        int count = 0;
        for(int j = 0; j < N; j++)
        {
            if(graph[i][j] != 0)
            {
                cout << i << "-" << j << " ";
                count++;
            }
        }
        if(count > 0) cout << endl;
    }
    cout << "------" << endl;
}
void printPath()
{
    cout << "Path:" << endl;
    
    for(int i = 0; i < pX; i++)
    {
        cout << path[i] << ", ";
    }
    cout << endl;
}