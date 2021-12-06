#include<iostream>
#include<algorithm>
using namespace std;
// find the minimum number of scalar multiplications to compute the maxrix-chain multiplication
int main(void)
{
    int n;
    cin >> n;
    int m[n + 1][n + 1];
    int p[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> p[i - 1] >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int target = 2; target <= n; target++) {
        for (int i = 1; i <= n - target + 1; i++) {
            int j = i + target - 1;
            m[i][j] = (1 << 30);
            for (int k = i; k <= j - 1; k++) {
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }
    cout << m[1][n];



    return 0;    
}