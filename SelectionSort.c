/*
//Time Complexity:O(n^2)
//Input
//N: a length of an array (1 <= N <= 100)
//A[i]: values in the array A
//Output
//the result after performing the bubble sort
//the number of swaps
*/
#include<stdio.h>



int selectionSort(int* A, int N){

    int i, j , sw=0, min;
    for(i = 0; i < N-1; i++){
        min=i;
        for(j = i;j < N; j++){
            if(A[j] < A[min])
                min = j;
        }

        if(i != min){
            sw++;
            //Do not put this code (the following three lines) outside the block of the if statement, or it may replace the value with zero in the original array.
            A[i] = A[i] ^ A[min];
            A[min] = A[i] ^ A[min];
            A[i] = A[i] ^ A[min];
        }
    }

    return sw;

}
int main() {
    int A[100], N, i, sw;

    scanf("%d",&N);
    for(i=0; i<N;i++){
        scanf("%d",&A[i]);
    }

    sw = selectionSort(A,N);

    for(i = 0; i< N; i++){
        if(i)
            printf(" ");
        printf("%d",A[i]);
    }

    printf("\n");
    printf("%d\n",sw);
    return 0;



}