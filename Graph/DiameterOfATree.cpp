#include<iostream>
#include<queue>
#include<vector>
#define INFTY (1 << 21)
using namespace std;

class Edge {
    public:
        int t, w;
        Edge()
        {

        }
        Edge(int t, int w): t(t), w(w)
        {

        }

};

class DiameterOfATree{
    public:
        vector<Edge> *G;
        int n;
        int *d;
        DiameterOfATree(int n): n(n) {
            G = new vector<Edge>[n];
            d = new int[n];
            int s, t, w;
            for (int i = 0; i < n - 1; i++) {
                cin >> s >> t >> w;
                G[s].push_back(Edge(t,w));
                G[t].push_back(Edge(s,w));
            }
        }
        void bfs(int s)
        {
            for (int i = 0; i < n; i++) {
                d[i] = INFTY;
            }
            queue<int> Q;
            Q.push(s);
            d[s] = 0;
            int u;
            while (!Q.empty()) {
                u = Q.front();
                Q.pop();
                for (int i = 0; i < (int)G[u].size(); i++) {
                    Edge e = G[u][i];
                    if (d[e.t] == INFTY) {
                        d[e.t] = d[u] + e.w;
                        Q.push(e.t);
                    }
                }
            }
        }

        void solve()
        {
            bfs(0);
            int maxv = 0;
            int trgt = 0;

            for (int i = 0; i < n; i++) {
                if (d[i] == INFTY)
                    continue;
                if (maxv < d[i]) {
                    maxv = d[i];
                    trgt = i;
                }
            }

            bfs(trgt);
            maxv = 0;
            for (int i = 0; i < n; i++) {
                if (d[i] == INFTY)
                    continue;
                maxv = max(maxv, d[i]);
            }

            cout << maxv << endl;
        }

        ~DiameterOfATree()
        {
            delete [] d;
            delete [] G;
        }

};

int main(void)
{
    int n;
    cin >> n;
    
    DiameterOfATree tree(n);
    tree.solve();

    return 0;
}