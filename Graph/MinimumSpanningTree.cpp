#include<iostream>
#define INFTY (1 << 21)
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;



int prim(int **M, int n)
{
    int color[n];
    int d[n];
    int p[n];

    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        d[i] =  INFTY;
        p[i] = -1;
    }

    d[0] = 0;
    int u, minv;
    while(true) {
        minv = INFTY;
        u = -1;
        for (int i = 0; i < n; i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1)
            break;
        color[u] = BLACK;
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && M[u][v] != INFTY) {
                if (d[v] > M[u][v]) {
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) {
            sum += M[i][p[i]];
        }
    }
    return sum;
}

int main(void)
{
    int n;
    cin >> n;

    int **M = new int*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[n];
    }

    int e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> e;
            M[i][j] = (e == -1) ? INFTY : e;
        }
    }

    cout << prim(M, n) << endl;

    for (int i = 0; i < n; i++) {
        delete [] M[i];
    }
    delete [] M;
    return 0;
}