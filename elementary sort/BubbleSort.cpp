/*
// Time Complexity:O(n^2) 
// Input
// N: a length of an array (1 <= N <= 100)
// A[i]: values in the array A
// Output
// the result after performing the bubble sort
// the number of swaps
*/
#include<iostream>
using namespace std;

int bubblesort(int A[], int N){
    int sw = 0;
    bool flag = 1;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j = N-1; j >= i+1;j--){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                flag =1;
                sw++;
            }

        }
    }
    return sw;
}


int main(){
    int N;
    cin >> N;
    int A[N], sw;
    for(int i=0;i<N;i++)
        cin >> A[i];
    sw = bubblesort(A,N);

    for(int i = 0; i < N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;


    return 0;
}