/*
*Input:
* n : number of nodes
* id left right: node number, left child node number, right child node number 
* e.g., 
* 9
* 0 1 4
* 1 2 3
* 2 -1 -1
* 3 -1 -1
* 4 5 8
* 5 6 7
* 6 -1 -1
* 7 -1 -1
* 8 -1 -1
* Output:
* e.g.,
* node 0: parent = -1, sibling = -1, degree = 2, depth = 0, height = 3, root
* node 1: parent = 0, sibling = 4, degree = 2, depth = 1, height = 1, internal node
* node 2: parent = 1, sibling = 3, degree = 0, depth = 2, height = 0, leaf
* node 3: parent = 1, sibling = 2, degree = 0, depth = 2, height = 0, leaf
* node 4: parent = 0, sibling = 1, degree = 2, depth = 1, height = 2, internal node
* node 5: parent = 4, sibling = 8, degree = 2, depth = 2, height = 1, internal node
* node 6: parent = 5, sibling = 7, degree = 0, depth = 3, height = 0, leaf
* node 7: parent = 5, sibling = 6, degree = 0, depth = 3, height = 0, leaf
* node 8: parent = 4, sibling = 5, degree = 0, depth = 2, height = 0, leaf
*/
#include<iostream>
using namespace std;
#define NIL -1

class BinaryTree {

    typedef struct {
        int p, left, right;
    }node;

    public:
        node* T;
        int* Depth;
        int* Height;
        int getSibling(int u);
        void print(int u);

        BinaryTree(int n)
        {
            T = new node[n];
            Depth = new int[n];
            Height = new int[n];
        }

        int *getDepth(int u, int d)
        {
            if ( u == NIL)
                return Depth;
        
            Depth[u] = d;
            getDepth(T[u].left, d + 1);
            getDepth(T[u].right, d + 1);
            return Depth;
        }

        int getHeight(int u)
        {
            int right_h = 0;
            int left_h = 0;
            if (T[u].left != NIL)
                left_h = getHeight(T[u].left) + 1;
            if (T[u].right != NIL)
                right_h = getHeight(T[u].right) + 1;
            return Height[u] = (left_h > right_h) ? left_h : right_h;
        }

        ~BinaryTree()
        {
            delete [] T;
            delete [] Depth;
            delete [] Height;
        }

};

int BinaryTree::getSibling(int u)
{
    if (T[u].p == NIL)
        return NIL;
    if ( T[T[u].p].left != u && T[T[u].p].left != NIL)
        return T[T[u].p].left;
    if ( T[T[u].p].right != u && T[T[u].p].right != NIL)
        return T[T[u].p].right;
    return NIL;
}

void BinaryTree::print(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    int deg = 0;
    if (T[u].left != NIL)
        deg++;
    if (T[u].right != NIL)
        deg++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << Depth[u] << ", ";
    cout << "height = " << Height[u] << ", ";    
    if (T[u].p == NIL)
        cout << "root" << endl;
    else if (T[u].left == NIL && T[u].right == NIL)
        cout << "leaf" << endl;
    else
        cout << "internal node" << endl;
}

int main(void)
{
    int n;
    cin >> n;
    BinaryTree tree(n);
    for (int i = 0; i < n; i++) {
        tree.T[i].p = tree.T[i].left = tree.T[i].right = NIL;
    }
    int v, l, r;
    for (int i = 0; i < n; i++) {
        cin >> v >> l >> r;
        tree.T[v].left = l;
        tree.T[v].right = r;
        if (l != NIL)
            tree.T[l].p = v;
        if (r != NIL)
            tree.T[r].p = v;
    }

    int *Depth = new int[n];
    int *Height = new int[n];
    int root;
    for(int i = 0; i < n; i++) {
        if (tree.T[i].p == NIL)
            root = i;
    }
    tree.getDepth(root, 0);
    tree.getHeight(root);
    for (int i = 0; i < n; i++)
        tree.print(i);

    return 0;
}