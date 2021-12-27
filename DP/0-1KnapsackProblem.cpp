#include<iostream>
#include<vector>
#include<algorithm>
#define DIAGONAL 1
#define TOP 0

using namespace std;

typedef struct {
    int value, weight;
}Item;

class Knapsack{
    public:
        int N, W;
        Item *items;
        int **C, **G;

        Knapsack(int N, int W): N(N), W(W) {
            C = new int*[N + 1];
            for (int i = 0; i < N + 1; i++) {
                C[i] = new int[W + 1];
            }
            G = new int*[N + 1];
            for (int i = 0; i < N + 1; i++) {
                G[i] = new int[W + 1];
            }
            items = new Item[N + 1];
            for (int i = 1; i <= N; i++) {
                cin >> items[i].value >> items[i].weight;
            }
        }
        void compute(int &maxValue, vector<int> &selection);

};

void Knapsack::compute(int &maxvalue, vector<int> &selection)
{
    for (int w = 0; w <= W; w++) {
        C[0][w] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        C[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (items[i].weight <= w) {
                C[i][w] = (items[i].value + C[i-1][w - items[i].weight] > C[i - 1][w]) ?
                (items[i].value + C[i-1][w - items[i].weight]) : (C[i - 1][w]);
                G[i][w] = (items[i].value + C[i-1][w - items[i].weight] > C[i - 1][w]) ?
                    DIAGONAL : TOP;
            } else {
                C[i][w] = C[i-1][w];
                G[i][w] = TOP;
            }
        }
    }

    maxvalue = C[N][W];
    selection.clear();
    for (int i = N, w = W; i >= 1; i--) {
        if (G[i][w] == DIAGONAL) {
            selection.push_back(i);
            w -= items[i].weight;
        }
    }
    reverse(selection.begin(), selection.end());
}

int main(void)
{
    int maxValue;
    vector<int> selection;
    int N, W;
    cin >> N >> W;
    Knapsack knapsack(N, W);
    knapsack.compute(maxValue, selection);
    cout << maxValue << endl;
    for (const auto& it: selection)
        cout << it << " item" << endl;

    return 0;
}