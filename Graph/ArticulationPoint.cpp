#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Articulation_Point{
    public:
        vector<int> *G;
        int n;
        int m;
        int *visit;
        int *low; //Record the minimum traversal moment
        int t;
        set <int> ap;
        Articulation_Point(int n, int m): n(n), m(m)
        {
            G = new vector<int>[n];
            visit = new int[n];
            low = new int[n];
            for (int i = 0; i < n; i++) {
                visit[i] = 0;
            }

            for (int i = 0; i < m; i++) {
                int s, t;
                cin >> s >> t;
                G[s].push_back(t);
                G[t].push_back(s);
            }
        
            t = 0;
        }

        void DFS(int prev, int current)
        {
            visit[current] = low[current] = ++t;

            int child = 0;
            bool point = false;
            int next;
            for (int j = 0; j < (int)G[current].size(); j++) {
                next = G[current][j];
                if (next != prev){
                    if (visit[next]) { //back edge
                        low[current] = min(low[current], visit[next]);
                    } else { // tree edge
                        child++;
                        DFS(current, next);

                        low[current] = min(low[current], low[next]);
                        if (low[next] >= visit[current])
                            point = true;
                    }
                }
            }
            // root or non-root
            if ((current == prev && child > 1) || (current != prev && point))
                ap.insert(current);

        }
        ~Articulation_Point()
        {
            delete [] G;
            delete [] visit;
            delete [] low;
        }

};

int main(void)
{
    int n, m;
    cin >> n >> m;    
    Articulation_Point point(n, m);
    point.DFS(0, 0); // if the parent of root is zero, then give (parent, root) = (0, 0)
    for (const auto& it : point.ap){
        cout << it << endl;
    }
    return 0;
}