#include<iostream>
#define Sentinel 2000000000
using namespace std;

int merge(int A[], int n, int left, int mid, int right)
{
    int cnt = 0;
    int subarrL = mid - left + 1;
    int subarrR = right - mid;
    int *L = new int[subarrL + 1];
    int *R = new int[subarrR + 1];
    L[subarrL] = R[subarrR] = Sentinel;
    for (int i = 0; i < subarrL; i++)
        L[i] = A[left + i];
    for (int i = 0; i < subarrR; i++)
        R[i] = A[mid + 1 + i];
    int index_L = 0;
    int index_R = 0;

    for(int k=left ; k <= right; k++) {
        if (L[index_L] <= R[index_R]) {
            A[k] = L[index_L++];
        } else {
            A[k] = R[index_R++];
            cnt += subarrL - index_L;
        }
    }
    delete [] L;
    delete [] R;
    return cnt;

}

int mergeSort(int A[], int n, int left, int right)
{
    int mid;
    int v1, v2, v3;
    if (left >= right)
        return 0;
    mid = (left + right) / 2;
    v1 = mergeSort(A, n, left, mid);
    v2 = mergeSort(A, n, mid + 1, right);
    v3 = merge(A, n, left, mid, right);
    return v1 + v2 + v3;
}

int main(void)
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ans = mergeSort(A, n, 0, n - 1);
    cout << ans << endl;
    return 0;
}