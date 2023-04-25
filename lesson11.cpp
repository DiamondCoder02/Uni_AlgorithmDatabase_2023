#include <iostream>
using namespace std;

const int N = 9; // number of edges
string items[N] = {"cipo", "also", "ing", "zokni", "zako", "nyakkendo", "ov", "melleny", "nadrag"};
int tasks[N][N] = {
    {0, 0, 0, 0, 0, 0, 1, 0, 0}, // 0 cipo
    {0, 0, 0, 0, 0, 0, 0, 0, 1}, // 1 also
    {0, 0, 0, 0, 0, 1, 1, 1, 0}, // 2 ing
    {1, 0, 0, 0, 0, 0, 0, 0, 0}, // 3 zokni
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4 zako
    {0, 0, 0, 0, 0, 0, 0, 1, 0}, // 5 nyakkendo
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, // 6 ov
    {0, 0, 0, 0, 1, 0, 0, 0, 0}, // 7 melleny
    {1, 0, 0, 0, 0, 0, 1, 0, 0}  // 8 nadrag
    //0  1  2  3  4  5  6  7  8
};
int schedule[N]; // edges in order
int sX = 0; // schedule index
int gX = 0; // next task index
int edges[N]; // edges of each task

void printEdges();
void printSchedule();

int main()
{
    printEdges();

    // Topological sorting
    for (int i = 0; i < N; i++) {
        edges[i] = 0;
        for (int j = 0; j < N; j++) { if (tasks[j][i] != 0) edges[i]++; };
    }

    while (sX < N) {
        for (int i = 0; i < N; i++) {
            if (edges[i] == 0) {
                edges[i] = -1;
                schedule[sX++] = i;
                for (int j = 0; j < N; j++) { if (tasks[i][j] != 0) edges[j]--; };
            }
        }
    }

    printSchedule();
}

void printEdges()
{
    cout << "Edges:" << endl;
    for (int i = 0; i < N; i++)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (tasks[i][j] != 0)
            {
                cout << items[i] << " -> " << items[j] << " , ";
                count++;
            }
        }
        if (count > 0)
            cout << endl;
    }
    cout << "------" << endl;
}
void printSchedule()
{
    cout << "Schedule:" << endl;

    for (int i = 0; i < sX; i++)
    {
        cout << items[schedule[i]] << ", ";
    }
    cout << endl;
}