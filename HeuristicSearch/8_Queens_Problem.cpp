#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define mm(a,b) memset(a,b,sizeof(a))
#define ACCELERATE (ios::sync_with_stdio(false),cin.tie(0))
using namespace std;
#define N 8
#define FREE -1
#define NOT_FREE 1

class Queen{
    public:
        int row[N];
        int col[N];
        int dpos[2 * N - 1];
        int dneg[2 * N - 1];
        bool X[N][N];
        Queen()
        {
            for (int i = 0; i < N; i++) {
                row[i] = FREE;
                col[i] = FREE;
            }
            
            for (int i = 0; i < 2 * N - 1; i++) {
                dpos[i] = FREE;
                dneg[i] = FREE;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    X[i][j] = false;
                }
            }
        }

        void printBoard()
        {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (X[i][j])
                        if (row[i] != j)
                            return;
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << ((row[i] == j) ? "Q" : ".");
                }
                cout << endl;
            }
        }

        void print()
        {
            for(int i = 0; i < N; i++) {
                if (i)
                    cout << " ";
                cout << row[i];
            }
            cout << endl;
        }

        void dfs(int i) {
            if (i == N) {
                printBoard();
                return;
            }

            for (int j = 0; j < N; j++) {
                if (col[j] == NOT_FREE || dpos[i + j] == NOT_FREE || dneg[i - j + N - 1] == NOT_FREE)
                    continue;
                row[i] = j;
                col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;

                dfs(i + 1);
                row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
            }
        }


};

int main()
{

    ACCELERATE;
    Queen q;
    mm(q.X, false);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        q.X[r][c] = true;
    }

    q.dfs(0);
    return 0;
}