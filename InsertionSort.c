/*
//Time Complexity:O(n^2)
//Input
//N: a length of an array (1 <= N <= 100)
//A[i]: values in the array A
//Output
//display intermediate and final results to trace the program flow.
*/
#include<stdio.h>

void trace(int A[], int N){
    int i;
    for(i=0; i< N;i++){
        if(i) 
            printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}
void insertionSort(int* A, int N){
    int j,i, v;
    for(int i=1;i<N;i++){
        v=A[i];
        j = i-1;
        while( j >= 0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        trace(A,N);
    }
}
int main(){
    int N,i;
    int A[100];

    scanf("%d",&N);
    for(i=0;i<N;i++) 
        scanf("%d", &A[i]);
    trace(A,N);
    insertionSort(A,N);

    return 0;
}