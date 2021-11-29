#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
    char com[20];
    priority_queue<int> pq;

    while(true) {
        cin >> com;
        if (com[0] == 'i') {
            int key;
            cin >> key;
            pq.push(key);
        } else if (com[1] == 'x') {
            cout << pq.top();
            pq.pop();
        } else if (com[0] == 'e') {
            break;
        }
    }

    return 0;
}