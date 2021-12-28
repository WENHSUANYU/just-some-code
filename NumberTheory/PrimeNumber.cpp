#include<iostream>

using namespace std;

bool isPrime(int x)
{
    if (x == 2)
        return true;
    if (x < 2 || x % 2 == 0)
        return false;
    
    for (int i = 3; i * i <= x; i = i + 2) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    int n;
    cin >> n;
    int x;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (isPrime(x))
            cnt++;
    } 
    cout << cnt << endl;


    return 0;
}