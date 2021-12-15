#include<iostream>
#include<vector>

using namespace std;

class DisjointSet {
    public:
        vector<int> rank, p;

        DisjointSet(int size)
        {
            rank.resize(size, 0);
            p.resize(size, 0);
            for (int i = 0; i < size; i++) {
                p[i] = -1;
                rank[i] = 0;
            }
        }

        int find(int node)
        {
            if(p[node] == -1)
                return node;
            return p[node] = find(p[node]);
        }

        void Union(int x, int y)
        {
            int root_x = find(x);
            int root_y = find(y);
            if (root_x != root_y){
                if (rank[root_x] > rank[root_y]) {
                    p[root_y] = root_x;
                } else {
                    p[root_x] = root_y;
                    if (rank[root_x] == rank[root_y]) 
                        rank[root_y]++;
                }
            }
        }
        ~DisjointSet(){};
};

int main(void)
{
    int n, q;
    cin >> n >> q;
    int com, num1, num2;
    DisjointSet set(n);

    for(int i = 0; i < q; i++) {
        cin >> com >> num1 >> num2;
        if (com == 0) {
            set.Union(num1, num2);
        } else if(com == 1){
            if(set.find(num1) == set.find(num2))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else {
            cout << "no command" << endl;
        }
        
    }

    return 0;
}