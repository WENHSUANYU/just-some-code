#include<iostream>
#include<vector>
using namespace std;

int solve(int *A, vector<vector<int>> &DP, int i, int m, int n)
{
    if (m == 0)
        return 1;
    if (i >= n)
        return 0;
    

    if (DP[i][m] != -1)
        return DP[i][m];
 
    if (solve(A, DP, i + 1, m, n) == 1)
        DP[i][m] = 1;
    else if (solve(A, DP, i + 1, m - A[i], n) == 1)
        DP[i][m] = 1;
    else
        DP[i][m] = 0;
    return DP[i][m];
}


int main(void)
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int count;
    int M;
    cin >> count;
    for (int i = 0; i < count ; i++){
        cin >> M;
        vector<vector<int>> DP(n, vector<int>(M + 1, -1));
        if (solve(A, DP, 0, M, n) == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    system("pause");
    return 0;
}