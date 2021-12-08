#include<iostream>
#include<stack>
#define WHITE 0
#define GRAY 1
#define BLACK 2

//This is a stack version
using namespace std;

class DFS{

    public:
        int n;
        int *color;
        int *d;
        int *f;
        int time;
        int *nt;
        int **M;
        DFS(int n)
        {
            this->n = n;
            this->color = new int[n];
            this->d = new int[n];
            this->f = new int[n];
            this->nt = new int[n];
            this->M = new int*[n];
            for (int i = 0; i < n; i++) {
                M[i] = new int[n];
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    M[i][j] = 0;
                }
            }
            for (int i = 0; i < n; i++) {
                this->color[i] = WHITE;
                this->nt[i] = 0;
            }
            this->time = 0;
        }
        void dfs_visit(int r);
        int next(int u);
        ~DFS();
        void print_M();
};

void DFS::dfs_visit(int r)
{
    for (int i = 0; i < n; i++) {
        nt[i] = 0;
    }
    stack<int> S;
    S.push(r);
    color[r] = GRAY;
    d[r] = ++time;

    while (!S.empty()) {
        int u = S.top();
        int v = next(u);
        if (v != -1) {
            if (color[v] == WHITE) {
                color[v] = GRAY;
                d[v] = ++time;
                S.push(v);
            }
        } else {
            S.pop();
            color[u] = BLACK;
            f[u] = ++time; 
        }
    }    
}

int DFS::next(int u)
{
    for (int v = nt[u]; v < n; v++) {
        //Record which node was last searched
        nt[u] = v + 1;
        if (M[u][v])
            return v;
    }
    return -1;
}

DFS::~DFS()
{
    delete [] color;
    delete [] d; 
    delete [] f;
    delete [] nt;
    for (int i = 0; i < n; i++) {
        delete [] M[i];
    }
    delete [] M;
}

void DFS::print_M()
{
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j)
                cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }
}



int main(void)
{
    int n;
    cin >> n;
    DFS dfs(n);
    int u, k, v;

    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            cin >> v;
            v--;
            dfs.M[u][v] = 1;
        }
    }

    for (int u = 0; u < n; u++) {
        if (dfs.color[u] == WHITE)
            dfs.dfs_visit(u);
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << dfs.d[i] << " " << dfs.f[i] << endl; 
    }

    return 0;
}