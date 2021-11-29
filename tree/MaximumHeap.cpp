#include<iostream>
#include<algorithm>
using namespace std;

class Heap{

    public:
        int H;
        int* A;
        Heap(int H){
            this->H = H;
            A = new int[H + 1];
            for (int i = 1; i <= H; i++) {
                cin >> A[i];
            }
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
        void buildMaxHeap()
        {
            for (int i = H / 2; i >= 1; i--) {
                maxHeapify(i);
            }
        
        }
        ~Heap(){
            delete [] A;
        }
};


int main(void)
{
    int H;
    cin >> H;
    Heap heap(H);

    heap.buildMaxHeap();

    for (int i = 1; i <= H; i++) {
        cout << " " << heap.A[i];
    }
    cout << endl;
    return 0;
}
