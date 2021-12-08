#include<iostream>
#include<queue>
#define INFTY (1 << 21)
using namespace std;

class BFS{
    public:
        int n;
        int **M;
        int *d;
        BFS(int n)
        {
            this->n = n;
            d = new int[n];
            M = new int*[n];
            for (int i = 0; i < n; i++) {
                M[i] = new int[n];
            }
        }
        void BFS_init(int u);
        ~BFS();

};

void BFS::BFS_init(int s)
{
    queue<int> q;
    q.push(s);
    for (int i = 0; i < n; i++) {
        d[i] = INFTY;
    }
    d[s] = 0;
    int u;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (M[u][v] == 0)
                continue;
            if (d[v] != INFTY)
                continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << ((d[i] == INFTY) ? (-1) : (d[i])) << endl;
    }

}

BFS::~BFS()
{
    delete [] d;
    for (int i = 0; i < n; i++) {
        delete [] M[i];
    }
    delete [] M;
}

int main(void)
{
    int n;
    cin >> n;
    BFS bfs(n);
    int u, k, v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bfs.M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++){
            cin >> v;
            v--;
            bfs.M[u][v] = 1;
        }
    }
    
    bfs.BFS_init(0);

    return 0;
}