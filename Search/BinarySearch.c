/*
* Input
* n: int 
* A[] (in increasing order): int
* q: int
* the number of q: int
* Output 
* sum (the total repeated number): int
*/
#include<stdio.h>

int binarysearch(int A[], int k, int n)
{
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = left + ((right - left) >> 1);
        if (k == A[mid])
            return 1;
        if (k > A[mid])
            left = mid + 1;
        else
            right = mid;
        
    }
    return 0;
}

int main(){
    int i, q, k, n;
    int sum = 0;
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &k);
        if (binarysearch(A,k,n))
            sum++;
    }
    printf("%d\n", sum);
}