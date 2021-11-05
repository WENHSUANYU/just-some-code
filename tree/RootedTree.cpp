#include<iostream>

using namespace std;
#define NIL -1

// left-child right-sibling representation
typedef struct{
    int p, l, r;
}node;


void print(node *T, int depth[], int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << depth[u] << ", ";

    if (T[u].p == NIL)
        cout << "root, ";
    else if (T[u].l == NIL)
        cout << "leaf, ";
    else
        cout << "internal node, ";
    
    cout << "[";
    for (int i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
        if (i)
            cout << ", ";
        cout << c;
    }

    cout << "]" << endl;
}

int* getDepth(node *T, int depth[], int u, int p)
{
    depth[u] = p;
    if (T[u].r != NIL)
        getDepth(T, depth, T[u].r, p);
    if (T[u].l != NIL)
        getDepth(T, depth, T[u].l, p + 1);
    return depth;
}

int main(void)
{
    int n;
    cin >> n;
    node T[n];
    int* Depth = new int[n];
    for (int i = 0; i < n; i++) {
        T[i].p = NIL;
        T[i].l = NIL;
        T[i].r = NIL;
    }
    // node number, degree, child node number 
    int v, d, c;
    //child node, sibling node
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> v >> d;
        for (int j = 0; j < d; j++) {
            cin >> c;
            if ( j == 0)
                T[v].l = c;
            else
                T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }

    for (int i = 0; i < n; i++) {
        if (T[i].p == NIL)
            r = i;
    }
    Depth = getDepth(T, Depth, r, 0);

    for(int i = 0; i < n; i++)
        print(T, Depth, i);

    return 0;
}