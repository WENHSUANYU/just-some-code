#include<iostream>
#include<vector>
#include<algorithm>
#define INFTY (1 << 30)
using namespace std;

class Heap{

    public:
        int H;
        vector<int> A;
        Heap(int H){
            this->H = H;
            A.push_back(-1);
        }
        void maxHeapify(int i)
        {
            int l, r, largest;
            l = 2 * i;
            r = 2 * i + 1;
            if (l <= H && A[l] > A[i])
                largest = l;
            else
                largest = i;

            if (r <= H && A[r] > A[largest])
                largest = r;

            if (largest != i) {
                swap(A[i], A[largest]);
                maxHeapify(largest);
            }
        }
        /*
        * void buildMaxHeap()
        * {
        *    for (int i = H / 2; i >= 1; i--) {
        *        maxHeapify(i);
        *    }
        *
        * }
        */
        int extract()
        {
            int max;
            if (H < 1)
                return -INFTY;
            max = A[1];
            A[1] = A[H--];
            maxHeapify(1);
            return max;
        }

        void increaseKey(int i, int key)
        {
            if (key < A.at(i))
                return;
            A.at(i) = key;
            while(i > 1 && A[i/2] < A[i]) {
                swap(A.at(i), A.at(i / 2));
                i = i / 2;
            }
        }

        void insert(int key)
        {
            H++;
            A.push_back(-1 * INFTY);
            increaseKey(H, key);
        }
        ~Heap(){
            A.clear();
        }
};


int main(void)
{
    Heap heap(0);

    char com[10];
    int key;
    while (true) {
        cin >> com;
        if (com[0] == 'e' && com[1] == 'n')
            break;
        if (com[0] == 'i') {
            cin >> key;
            heap.insert(key);
        } else {
            cout << heap.extract();
        }
    }


    return 0;
}