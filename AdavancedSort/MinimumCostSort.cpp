#include<iostream>
#include<algorithm>
using namespace std;
static const int Num_MAX = 1000;
static const int Value_MAX = 10000;



int solve(int A[], int n, int s)
{
    int max = 0;
    int ans = 0;
    int *B = new int[n];
    bool *tag = new bool[n];
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
        if (max < B[i])
            max = B[i];
        tag[i] = false;
    }
    sort(B, B + n);
    int *T = new int[max + 1];
    for (int i = 0 ; i < n; i++)
        T[B[i]] = i;
    for (int i = 0; i < n; i++) {
        if (tag[i])
            continue;
        int cur_index = i;
        int sum = 0;
        int m = Value_MAX;
        int numOfIndex = 0;
        while (1) {
            tag[cur_index] = true;
            numOfIndex++;
            int v = A[cur_index];
            m = min(m, v);
            sum += v;
            cur_index = T[v];
            if (tag[cur_index])
                break;
        }
        ans += min(sum + (numOfIndex - 2) * m, sum + m + (numOfIndex + 1) * s);
    }
    return ans;

}

int main()
{
    int n;
    cin >> n;
    int smallest_num = Value_MAX;
    int A[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int ans = solve(A, n, smallest_num);
    cout << ans << endl;

    return 0;
}