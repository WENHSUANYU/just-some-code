#include<iostream>
#include<algorithm>
#define INFTY (1 << 30)
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int C[m + 1];
    int T[n + 1];

    for (int i = 1; i <= m; i++) {
        cin >> C[i];
    }

    for (int i = 0; i <= n + 1; i++) {
        T[i] = INFTY;
    }
    T[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j + C[i] <= n; j++) {
            T[j + C[i]] = min(T[j + C[i]], T[j] + 1);
        }
    }

    cout << T[n] << endl;
    return 0;
}