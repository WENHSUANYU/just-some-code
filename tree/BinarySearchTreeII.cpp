#include<iostream>
#include<string>

using namespace std;

class BST{

    typedef struct node {
        int key;
        node *parent;
        node *l;
        node *r;
    }node;

    public:
    node *tree = NULL;

    bool find(node *tree, int val)
    {
        while (tree != nullptr && tree->key != val) {
            if ( val < tree->key)
                tree = tree->l;
            else
                tree = tree->r;
        }
        if (tree == nullptr)
            return false;
        else
            return true;

    }

    void insert(int k)
    {
        node *y = tree;
        node *x = NULL; //trailing of y;
        node* new_node = new node{k, 0, 0, 0};
        if (tree == nullptr) {
            tree = new_node;
        }
        else {
            while (y != nullptr) {
                x = y;
                if (y->key > new_node->key)
                    y = y->l;
                else
                    y = y->r;
            }
            new_node->parent = x;
            if (x->key > new_node->key)
                x->l = new_node;
            else
                x->r = new_node;
        }
        
    }

    void inorder(node *t)
    {
        if (t == nullptr)
            return;
        inorder(t->l);
        cout << " " << t->key;
        inorder(t->r);
    }

    void preorder(node *t)
    {
        if (t == nullptr)
            return;
        cout << " " << t->key;
        preorder(t->l);
        preorder(t->r);
    }
    void delete_node(node *t)
    {
        if (t == nullptr)
            return;
        delete_node(t->l);
        delete_node(t->r);
        delete t;
    }

};

int main(void)
{
    int n;
    cin >> n;
    BST t;
    string str;
    int x;
    for (int i = 0; i < n; i++){
        cin >> str;
        if (str[0] == 'f') {
            cin >> x;
            if ( t.find(t.tree, x))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        } else if (str[0] == 'i'){
            cin >> x;
            t.insert(x);
        } else if (str == "print") {
            cout << "Inorder:";
            t.inorder(t.tree);
            cout << endl;
            cout << "Preorder:";
            t.preorder(t.tree);
            cout << endl;
        }

    }
    t.delete_node(t.tree);
    return 0;
}