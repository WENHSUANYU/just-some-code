/*
//Input
// n: a length of an array (1 <= N <= 1,000,000)
// A[]: values in the array A
//Output
// m : a length of gap sequence
// G : values in the gap sequence
// cnt : count the number of executions in the while loop
// A[]:show values in increasing order (n lines)
*/
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#define  ll long long
using namespace std;

ll cnt;

void insertionSort(int A[], int n, int g){
    for(int i = g; i < n ; i++){
        int v = A[i];
        int j = i - g;
        while( j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j-=g;
            cnt++;

        }
        A[j+g] = v;
    }

}
void shellSort(int A[], int n){
    vector<int> G;
    for(int h = 1; ; ){
        if(h > n)
            break;
        G.push_back(h);
        h = 3*h + 1;
    }
    cout << G.size() << endl;
    for(int i = G.size() -1 ; i >= 0 ; i--){
        cout << G[i];
        if(i) 
            cout << " ";
    }
    cout << endl;
    for(int i = G.size()-1 ; i >= 0 ; i--){
        insertionSort(A,n,G[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int* A = new int[n]{0} ;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }


    shellSort(A, n);
    cout << cnt << endl;
    for(int i = 0 ; i < n ; i++){
        cout << A[i] << endl;
    }

    delete [] A;
    return 0;

}