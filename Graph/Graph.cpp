#include<iostream>

using namespace std;

int main(void)
{
    //number of nodes
    int n;
    cin >> n;
    int M[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }
    //node number, degree
    int u, k;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        //take node number 0 as the starting node
        u--;
        int v;
        for (int j = 0; j < k; j++) {
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j)
                cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }

    return 0;
}