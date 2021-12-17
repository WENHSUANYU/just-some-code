#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;
//DFS: using recursion
class TopologicalSort{

    public:
        int *color;
        vector<int> *G;
        list<int> *out;
        int n;
        TopologicalSort(int n): n(n)
        {
            color = new int[n];
            G = new vector<int>[n];
            out = new list<int>[n];
            for (int i = 0; i < n; i++)
                color[i] = 0;
        }

        void DFS(int u);
        void print();

};

void TopologicalSort::DFS(int u)
{
    color[u] = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (color[v] == 0)
            DFS(v);
    }
    out->push_front(u);
}

void TopologicalSort::print()
{
    for(auto it : *out) {
        cout << it << endl;
    }
}

int main(void)
{
    int vertex, edge;
    cin >> vertex >> edge;
    TopologicalSort t(vertex);
    int v1, v2;
    for (int i = 0; i < edge; i++) {
        cin >> v1 >> v2;
        t.G[v1].push_back(v2);
    }

    for (int i = 0; i < vertex; i++) {
        if(t.color[i] == 0)
            t.DFS(i);
    }
    t.print();

    return 0;
}