#include <iostream>
using namespace std;

const int N = 9;
int graph[N][N] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0, }, //0   
    {4, 0, 8, 0, 0, 0, 0,11, 0, }, //1
    {0, 8, 0, 7, 0, 4, 0, 0, 2, }, //2
    {0, 0, 7, 0, 9,14, 0, 0, 0, }, //3
    {0, 0, 0, 9, 0,10, 0, 0, 0, }, //4
    {0, 0, 4,14,10, 0, 2, 0, 0, }, //5
    {0, 0, 0, 0, 0, 2, 0, 1, 6, }, //6
    {8,11, 0, 0, 0, 0, 1, 0, 7, }, //7
    {0, 0, 2, 0, 0, 0, 6, 7, 0, }  //8
//   0  1  2  3  4  5  6  7  8
};
int sTree[N][N];
bool check[N];

void init();
void printEdges(int[][N], bool);

int main() 
{
    init();
    printEdges(graph, false);
    
    // Prim's algorithm for minimum spanning tree, starting from smallest edge
	int min = 0;
	int minI = 0;
	int minJ = 0;
	check[0] = true;
	for(int k = 0; k < N-1; k++) {
		min = 0;
		minI = 0;
		minJ = 0;
		for(int i = 0; i < N; i++) {
			if(check[i]) {
				for(int j = 0; j < N; j++) {
					if(!check[j] && graph[i][j] != 0) {
						if(min == 0 || min > graph[i][j]) {
							min = graph[i][j];
							minI = i;
							minJ = j;
						}
					}
				}
			}
		}
		check[minJ] = true;
		sTree[minI][minJ] = min;
		sTree[minJ][minI] = min;
	}

/*
	for(int k = 0; k < N-1; k++) {
		min = 0;
		minI = 0;
		minJ = 0;
		for(int i = 0; i < N; i++) {
			if(check[i]) {
				for(int j = 0; j < N; j++) {
					if(!check[j] && graph[i][j] != 0) {
						if(min == 0 || min > graph[i][j]) {
							min = graph[i][j];
							minI = i;
							minJ = j;
						}
					}
				}
			}
		}
		check[minJ] = true;
		sTree[minI][minJ] = min;
		sTree[minJ][minI] = min;
	}*/

    printEdges(sTree, true);
}

void init()
{
    for(int i = 0; i < N; i++)
    {
        check[i] = false;
    }
	
    for(int i = 0; i < N; i++)
    {
		for(int j = 0; j < N; j++)
		{
			sTree[i][j] = 0;
		}
    }
}
void printEdges(int matrix[][N], bool isResult)
{
    int edges = 0;
    int weight = 0;
    cout << (isResult ? "Tree:" : "Graph:") << endl;
    for(int i = 0; i < N; i++)
    {
        int count = 0;
        for(int j = 0; j < N; j++)
        {
            if(matrix[i][j] != 0 && matrix[i][j] == matrix[j][i])
            {
                cout << "(" << i << ")--"; 
                cout << matrix[i][j];
                cout << "--(" << j << ") , ";
                count++;
                edges++;
                weight += matrix[i][j];
            }
        }
        if(count > 0) cout << endl;
    }
    edges /= 2;
    weight /= 2;
    cout << "Edges: " << edges << endl;
    if(isResult) cout << "Weight: " << weight << endl;
    cout << "------" << endl;
}