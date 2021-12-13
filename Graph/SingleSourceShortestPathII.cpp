#include<iostream>
#include<algorithm>
#include<queue>
#define INFTY (1 << 21)
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
//Data structure:priority_queue、adjacent list
void dijkstra(vector<pair<int, int>> *adj, int n)
{
    priority_queue<pair<int, int>> pq;
    int d[n];
    int color[n];
    for (int i = 0; i < n; i++) {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;
    pq.push(make_pair(d[0], 0));
    color[0] = GRAY;

    while (!pq.empty()) {
        auto f = pq.top();
        pq.pop();
        int u = f.second;
        
        color[u] = BLACK;
        //d[u] have the the value of the shortest path
        //f may retain the value of the non-shortest path, thus let's drop it
        if (d[u] < f.first * (-1))
            continue;

        for (uint32_t j = 0; j < adj[u].size(); j++) {
            //adjacent node num
            int adj_node = adj[u][j].first; 
            if (color[adj_node] == BLACK)
                continue;
            if (d[adj_node] > d[u] + adj[u][j].second) {
                d[adj_node] = d[u] + adj[u][j].second;
                pq.push(make_pair(d[adj_node] * -1, adj_node));
                color[adj_node] = GRAY;
            }
         }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }

}
int main(void)
{
    int n;
    cin >> n;
    int node, outdegree, adj_node, weight;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < n; i++) {
        cin >> node >> outdegree;
        for (int j = 0; j < outdegree; j++) {
            cin >> adj_node >> weight;
            adj[node].push_back(make_pair(adj_node, weight));
        }
    }

    dijkstra(adj, n);

    return 0;
}