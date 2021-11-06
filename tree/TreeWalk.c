#include<stdio.h>
#define NIL -1

typedef struct {
    int p, l, r;
}node;

void PreOrder(int u, node *T)
{
    if (u == NIL)
        return;
    printf(" %d", u);
    PreOrder(T[u].l, T);
    PreOrder(T[u].r, T);
}

void InOrder(int u, node *T)
{
    if (u == NIL)
        return;
    InOrder(T[u].l, T);
    printf(" %d", u);
    InOrder(T[u].r, T);
}

void PostOrder(int u, node *T)
{
    if (u == NIL)
        return;
    PostOrder(T[u].l, T);
    PostOrder(T[u].r, T);
    printf(" %d", u);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    node T[n];
    for (int i = 0; i < n; i++)
        T[i].p = NIL;
    int v, l, r;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v, &l, &r);
        T[v].l = l;
        T[v].r = r;
        if (l != NIL)
            T[l].p = v;
        if (r != NIL)
            T[r].p = v;
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (T[i].p == NIL)
            root = i;
    }

    printf("Preorder\n");
    PreOrder(root, T);
    printf("\n");
    printf("Inorder\n");
    InOrder(root, T);
    printf("\n");
    printf("Postorder\n");
    PostOrder(root, T);
    printf("\n");
    return 0;
}