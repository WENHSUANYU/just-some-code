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
    node *treeMinimum(node *x)
    {
        while (x->l != nullptr)
            x = x->l;
        return x;
    }

    //The utility is used to search for a first node by which the target node followed in inorder traversal.
    //Here, it is only used when the node has two children.
    node *treeSuccessor(node *target)
    {
        if (target->r != nullptr)
            return treeMinimum(target->r);
        /* test code
        else{
            cout << "here" << endl;
            node *node1 = new node{-1, 0, 0, 0};
            return  node1;
        }
        */
        /*
        node *y = target->parent;
        while (y != nullptr && target = y->right) {
            target = y;
            y = y->parent;
        }
        return y;
        */
    }

    void treeDelete(int key)
    {
        node *target = nullptr;
        node *tmp = tree;
        //find the target node
        while (tmp != nullptr && tmp->key != key) {
            if ( key < tmp->key)
                tmp = tmp->l;
            else
                tmp = tmp->r;
        }
        target = tmp;

        //node y
        //node x is the child node of y 
        node *y = new node{-2000000001, 0, 0, 0};
        node *x;
        //find y
        //case i and ii
        if (target->l == nullptr || target->r == nullptr)
            y = target;
        //case iii
        else
            y = treeSuccessor(target);
        //find x
        //case i、ii、iii
        if (y->l != nullptr)
            x = y->l;
        else
            x = y->r;

        //set the parent of node x
        if (x != nullptr)
            x->parent = y->parent;
        //set the parent of node y
        if (y->parent == nullptr) {
            tree = x;
        } else {
            if (y->parent->l == y) {
                y->parent->l = x;
            } else {
                y->parent->r = x;
            }
        }
        //case iii
        if (y != target) {
            target->key = y->key;
        }

        delete y;
    }



    void delete_all(node *t)
    {
        if (t == nullptr)
            return;
        delete_all(t->l);
        delete_all(t->r);
        delete t;
    }

};

int main(void)
{
    int n;
    cin >> n;
    string str;
    BST t;
    for (int i = 0; i < n; i++) {
        cin >> str;
        int value;
        if (str == "find") {
            cin >> value;
            if (t.find(t.tree, value))
                cout << "yes" << endl;
            else 
                cout << "no" << endl;
        } else if (str == "insert") {
                cin >> value;
                t.insert(value);

        } else if (str == "print") {
            cout << "Inorder: ";
            t.inorder(t.tree);
            cout << endl;
            cout << "Preorder: ";
            t.preorder(t.tree);
            cout << endl;
        } else if (str == "delete") {
            cin >> value;
            t.treeDelete(value);
        }
        
    }
    t.delete_all(t.tree);

    return 0;
}