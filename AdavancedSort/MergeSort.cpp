#include<iostream>
using namespace std;
#define MAX 2000000000


int cnt = 0;
void merge(int A[], int left, int mid, int right)
{
    int sub_arrayL = mid - left + 1;
    int sub_arrayR = right - mid;
    int *L = new int[sub_arrayL + 1];
    int *R = new int[sub_arrayR + 1];
    for (int i = 0; i < sub_arrayL; i++)
        L[i] = A[left + i];
    for (int j = 0; j < sub_arrayR; j++)
        R[j] = A[mid + 1 + j];
    L[sub_arrayL] = R[sub_arrayR] = MAX;
    int index_L = 0;
    int index_R = 0;
    for (int i = left; i <= right; i++) {
        cnt++;
        if (L[index_L] <= R[index_R]) {
            A[i] = L[index_L];
            index_L++;
        } else {
            A[i] = R[index_R];
            index_R++;
        }
    }
    delete [] L;
    delete [] R;

}


void mergeSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}


int main()
{
    int n,i;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    mergeSort(A,0,n-1);
    for ( i = 0; i < n; i++) {
        if (i)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt;

    return 0;
}