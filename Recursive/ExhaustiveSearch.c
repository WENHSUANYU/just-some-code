/*
* Input
* A: int [n] (n <= 20)
* 1 <= the value of A <= 2000 
* q: int (q <= 200)
* m: int (1 <= m <= 2000)
* Output
* yes | no
*/
#include<stdio.h>

typedef struct {
    int n;
    int A[20];
}arr_n;

int solve(arr_n arr, int i, int M)
{
    if (M == 0)
        return 1;
    if (i >= arr.n)
        return 0;
    int res = solve(arr, i + 1, M) || solve(arr, i + 1, M - arr.A[i]);
    return res;
}

int main(){
    arr_n arr;
    int q, M, i;
    scanf("%d", &arr.n);
    for (i = 0; i < arr.n; i++)
        scanf("%d", &arr.A[i]);
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d", &M);
        if (solve(arr, 0, M))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}