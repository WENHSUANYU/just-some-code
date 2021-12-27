#include<iostream>
#include<algorithm>

using namespace std;

int lis(int n, int *A, int *L){
    L[0] = A[0];
    int length = 1;

    for (int i = 1; i < n; i++) {
        if (L[length - 1] < A[i]) {
            L[length++] = A[i];
        } else {
            if (*lower_bound(L, L+length, A[i]) == L[length - 1])
                *lower_bound(L, L+length, A[i]) = A[i];
        }
    }

    return length;
}



int main(void)
{
    int n;
    cin >> n;
    int A[n + 1];
    int L[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int result = lis(n, A, L);
    cout << result << endl;
    for (int i = 0; i < result; i++) {
        cout << L[i] << " ";
    }
    return 0;
}