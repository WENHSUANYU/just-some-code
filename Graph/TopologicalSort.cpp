#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;

class TopologicalSort{

    public:
        int n;
        int *color;
        list<int> *out;
        vector<int> *G;
        int *indegree;
        TopologicalSort(int n): n(n){
            color = new int[n];
            out = new list<int>[n];
            G = new vector<int>[n];
            indegree = new int[n];
            for (int i = 0; i < n; i++) {
                color[i] = 0; //WHITE
                indegree[i] = 0;
            }
        }
        void bfs(int u);
        void tsort();
        ~TopologicalSort();
};

void TopologicalSort::bfs(int u)
{
    queue<int> q;
    q.push(u);
    color[u] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        out->push_back(u);
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i];
            indegree[v]--;
            if (indegree[v] == 0 && color[v] == 0) {
                color[v] = 1;
                q.push(v);
            }
        }
    }

}

void TopologicalSort::tsort()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            int v = G[i][j];
            indegree[v]++;
        }
    }

    for (int u = 0; u < n; u++) {
        if (indegree[u] == 0 && color[u] == 0)
            bfs(u);
    }

    for (const auto &it : *out)
    {
        cout << it << endl;
    }
}

TopologicalSort::~TopologicalSort(){
    delete [] color;
    delete [] out;
    delete [] G;
    delete [] indegree;
}

int main(void)
{
    int vertex, edge_num;
    cin >> vertex >> edge_num;

    int v1, v2;
    TopologicalSort t(vertex);
    
    for (int i = 0; i < edge_num; i++) {
        cin >> v1 >> v2;
        t.G[v1].push_back(v2);
    }

    t.tsort();

    return 0;
}
