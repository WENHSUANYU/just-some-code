#include<iostream>
#define INFTY (1 << 21)
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;
//Data structure: array
//Dijkstra's algorithm
void dijkstra(int **M, int n)
{
    int d[n], color[n];

    for (int i = 0; i < n; i++) {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;
    color[0] = 0;
    while(true) {
        int minv = INFTY;
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
        if (minv == INFTY)
            break;
        color[u] = BLACK;
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && M[u][v] != INFTY) {
                if (d[v] > d[u] + M[u][v]) {
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
            }
        }

    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << (d[i] != INFTY ? d[i] : -1) << endl;
    }
}

int main(void)
{
    int n;
    cin >> n;
    int **M = new int*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = INFTY;
        } 
    }

    int node_x, outdegree, node_y, weight;

    for (int i = 0; i < n; i++) {
        cin >> node_x >> outdegree;
        for (int j = 0; j < outdegree; j++) {
            cin >> node_y >> weight;
            M[node_x][node_y] = weight;
        }
    }

    dijkstra(M, n);

    for (int i = 0; i < n; i++) {
        delete [] M[i];
    }
    delete [] M;

    return 0;
}