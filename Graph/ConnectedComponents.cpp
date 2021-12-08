#include<iostream>
#include<vector>
#include<stack>
#define NIL -1
using namespace std;
//Connected components concept
class Components{

    public:
        int n;
        vector<int> *G;
        int *color;
        int m;
        Components(int n, int m)
        {
            this->n = n;
            this->m = m;
            int s, t;
            G = new vector<int>[n];
            for (int i = 0; i < m; i++) {
                //both sides of friendship
                cin >> s >> t;
                G[s].push_back(t);
                G[t].push_back(s);
            }
            color = new int[n];

        }        

        void dfs(int r, int c)
        {
            stack<int> S;
            S.push(r);
            color[r] = c;
            while (!S.empty()) {
                int u = S.top();
                S.pop();
                for (int i = 0; i < (int)G[u].size(); i++) {
                    int v = G[u][i];
                    if (color[v] == NIL) {
                        color[v] = c;
                        S.push(v);
                    }
                }
            }

        }

        void assignColor()
        {
            int id = 1;
            for (int i = 0; i < n; i++)
                color[i] = NIL;
            for (int u = 0; u < n; u++) {
                if (color[u] == NIL)
                    dfs(u, id++);
            }

        }

        ~Components(){
            delete [] color;
            delete [] G;
        }

};

int main(void)
{
    //number of users, number of friendships
    int n, m;
    cin >> n >> m;
    Components g(n, m);

    g.assignColor();
    //Check if there is a friendship between the two sides.
    int check;
    cin >> check;

    int s, t;
    for (int i = 0; i < check; i++) {
        cin >> s >> t;
        if (g.color[s] == g.color[t])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }


    return 0;
}