#include<iostream>
#include<array>
using namespace std;
// n <= 45

int fib(int n, array<int, 50> &F) {
    if (n <= 1)
        return F[n] = 1;
    if (F[n] != -1)
        return F[n];
    return F[n] = fib(n - 1, F) + fib(n - 2, F);
}


int main(void)
{
    int n;
    cin >> n;
    array<int, 50>F;
    F.fill(-1);
    cout << fib(n, F) << endl;

    return 0;
}