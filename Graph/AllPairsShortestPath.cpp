#include<iostream>
#include<algorithm>
#define INFTY (1LL << 32)
using namespace std;


//WarshallFloyd's algorithm
void WarshallFloyd(vector<vector<long long>> &d, int vertex)
{
    for (int k = 0; k < vertex; k++) {
        for (int i = 0; i < vertex; i++) {
            if (d[i][k] == INFTY)
                continue;
            for (int j = 0; j < vertex; j++) {
                if (d[k][j] == INFTY)
                    continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(void)
{
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<long long>> d(vertex, vector<long long>(vertex, 0LL));

    int v1, v2, weight;
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            d[i][j] = (i == j ? 0LL : INFTY);
        }
    }

    for (int i = 0; i < edge; i++) {
        cin >> v1 >> v2 >> weight;
        d[v1][v2] = weight;
    }

    WarshallFloyd(d, vertex);

    bool negative_cycle = false;

    for (int i = 0; i < vertex; i++) {
        if (d[i][i] < 0)
            negative_cycle = true;
    }

    if (negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                if (j)
                    cout << " ";
                if (d[i][j] == INFTY)
                    cout << "INF";
                else
                    cout << d[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}