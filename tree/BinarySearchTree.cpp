#include<iostream>
#include<string>

using namespace std;

class BST{

    typedef struct node{
        int key;
        node *p;
        node *l;
        node *r;
    }node;

    public:
        node *tree = NULL;

        void insert(int k)
        {
            node *new_node = new node{k, 0, 0, 0};
            node *x = tree;
            node *y = NULL;

            if (tree == nullptr) {
               tree = new_node;
            }
            else{

                while (x != NULL) {
                    y = x;
                    if (new_node->key < x->key)
                        x = x->l;
                    else
                        x = x->r;
                }
                new_node->p = y;
                if (new_node->key < y->key) {
                    y->l = new_node;
                } else {
                    y->r = new_node;
                }
            }
        }

        void inorder(node *r)
        {
            if (r == nullptr)
                return;
            inorder(r->l);
            cout << " " << r->key;
            inorder(r->r);
        }

        void preorder(node *r)
        {
            if (r == nullptr)
                return;
            cout << " " << r->key;
            preorder(r->l);
            preorder(r->r);
        }
};

int main(void)
{
    int n;
    cin >> n;

    BST tree;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "insert") {
            int value;
            cin >> value;
            tree.insert(value);
        } else if (str == "print") {
            cout << "Inorder:";
            tree.inorder(tree.tree);
            cout << endl;
            cout << "Preorder:";
            tree.preorder(tree.tree);
            cout << endl;
        }
    }
    

    return 0;
}