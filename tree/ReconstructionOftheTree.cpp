#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Tree{
    typedef struct{
        vector<int> in, pre,post;
    }travasal;

    public:
        travasal T;
        int post;
        void Reconstruction(int l, int r)
        {
            if (l >= r)
                return;
            int root = T.pre[post++];
            int m = distance(T.in.begin(), find(T.in.begin(), T.in.end(), root));
            Reconstruction(l, m);
            Reconstruction(m + 1, r);
            T.post.push_back(root);
        }
};

int main(void)
{
    int n;
    cin >> n;
    Tree tree;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        tree.T.pre.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        cin >> k;
        tree.T.in.push_back(k);
    }

    tree.post = 0;
    tree.Reconstruction(0, tree.T.pre.size());

    for (int i = 0; i < n; i++) {
        if (i)
            cout << " ";
        cout << tree.T.post[i];
    }
    cout << endl;

    return 0;
}