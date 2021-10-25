#include<stdio.h>
#define MAX 100000



int partition(int A[], int p, int r)
{
    int i = p;
    for (int j = p; j < r; j++) {
        if (A[j] <= A[r]) {
            A[i] = A[i] ^ A[j];
            A[j] = A[i] ^ A[j];
            A[i] = A[i] ^ A[j];
            i++;
        }
    }
    A[i] = A[i] ^ A[r];
    A[r] = A[i] ^ A[r];
    A[i] = A[i] ^ A[r];
    return i;
}

int main()
{
    int i, q, n;

    scanf("%d",&n);
    int A[n];
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    q = partition(A, 0, n-1);

    for (i = 0; i < n; i++) {
        if (i)
            printf(" ");
        if (i == q)
            printf("[");
        printf("%d", A[i]);
        if (i == q)
            printf("]");
    }
    printf("\n");
    return 0;

}