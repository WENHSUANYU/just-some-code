#include<iostream>
#include<map>
#include<cstdio>
#include<string>
using namespace std;

int main(void)
{
    int n;
    char str[10];
    char com[8];
    map<string, bool> T;

    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s %s", com, str);
        if (com[0] == 'i') {
            T[string(str)] = true;
        } else {
            if (T[string(str)])
                printf("yes\n");
            else
                printf("no\n");
        }
    }

    return 0;
}