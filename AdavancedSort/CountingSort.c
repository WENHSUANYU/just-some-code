#include<stdio.h>
#include<stdlib.h>

void countingsort(int *A, int n)
{
    int *B = (int *)malloc((n + 1)* sizeof(int));
    int max_A = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (max_A < A[i])
            max_A = A[i];
    }
    int *C = (int *)malloc((max_A + 1) * sizeof(int));
    for (int i = 0; i <= max_A; i++)
        C[i] = 0;
    for (int i = 0; i < n; i++)
        C[A[i]]++;
    for (int i = 1; i <= max_A; i++)
        C[i] = C[i] + C[i - 1];
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    for (int i = 1; i < n + 1; i++) {
        if (i > 1) 
            printf(" ");
        printf("%d", B[i]);
    }

    free(B);
    free(C);

}



int main()
{
    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    countingsort(A, n);

    free(A);
    return 0;     
}