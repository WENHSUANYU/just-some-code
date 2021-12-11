#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INFTY (1 << 21)

//Kruskal's algorithm

class Utility{

    int *parent;
    int *rank;

    public:
        Utility(int n)
        {
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++) {
                parent[i] = -1;
                rank[i] = 0;
            }
        }
        
        int find(int node)
        {
            if(parent[node] == -1)
                return node;
            return parent[node] = find(parent[node]);
        }

        void Union(int x, int y)
        {
            int s1 = find(x);
            int s2 = find(y);
            if (s1 != s2) {
                if (rank[s1] < rank[s2])
                {
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                } else {
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }
        }
};

class Graph{

    vector<vector<int>> edge;
    int V;
    public:
        Graph(int V)
        {
            this->V = V;
        }

        void addEdge(int x, int y, int w)
        {
            edge.push_back({w,x,y});
        }

        int kruskal_mst()
        {
            sort(edge.begin(), edge.end());
            Utility set(V);
            int sum = 0;

            for (const auto &it : edge) {
                int w = it[0];
                int x = it[1];
                int y = it[2];
                
                if (w != INFTY) {
                    if (set.find(x) != set.find(y)) {
                        set.Union(x, y);
                        sum += w;
                    }
                } else {
                    continue;
                }

            }

            return sum;
        }


};

int main(void)
{
    int n;
    cin >> n;
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            cin >> value;
            g.addEdge(i, j, (value == -1 ? INFTY : value));
        }
    }

    cout << g.kruskal_mst();
    
    return 0;
}