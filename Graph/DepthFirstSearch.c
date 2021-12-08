#include<stdio.h>
#include<stdlib.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

//This is a recursive version
typedef struct DFS{
    int n;
    int *color;
    int *d;
    int *f;
    int time;
    int **M;
}DFS;

void dfs_visit(DFS *dfs, int u)
{
    int v;
    dfs->color[u] = GRAY;
    dfs->d[u] = ++(dfs->time);
    for (v = 0; v < dfs->n; v++) {
        if (dfs->M[u][v] == 0)
            continue;
        if (dfs->color[v] == WHITE) {
            dfs_visit(dfs, v);
        }
    }
    dfs->color[u] = BLACK;
    dfs->f[u] = ++(dfs->time);
}

void dfs_init(DFS *dfs)
{
    for (int i = 0; i < dfs->n; i++) {
        dfs->color[i] = WHITE;
    }
    dfs->time = 0;
    for (int u = 0; u < dfs->n; u++) {
        if (dfs->color[u] == WHITE)
            dfs_visit(dfs, u);
    }

    for (int i = 0; i < dfs->n; i++) {
        printf("%d %d %d\n", i + 1, dfs->d[i], dfs->f[i]);
    }

}


int main(void)
{
    DFS dfs;
    scanf("%d", &dfs.n);
    dfs.color = (int *)malloc(dfs.n * sizeof(int));
    dfs.d = (int *)malloc(dfs.n * sizeof(int));
    dfs.f = (int *)malloc(dfs.n * sizeof(int));
    dfs.M = (int **)malloc(dfs.n * sizeof(int *));

    for (int i = 0; i < dfs.n; i++) {
        dfs.M[i] = (int *)malloc(dfs.n * sizeof(int));
    }
    for (int i = 0; i < dfs.n; i++) {
        for (int j = 0; j < dfs.n; j++) {
             dfs.M[i][j] = 0;
        }
    }

    int u, k, v;
    for (int i = 0; i < dfs.n; i++) {
        scanf("%d %d", &u, &k);
        u--;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            v--;
            dfs.M[u][v] = 1;
        }
    }
    dfs_init(&dfs);
    free(dfs.color);
    free(dfs.d);
    free(dfs.f);
    for (int i = 0; i < dfs.n; i++) {
        free(dfs.M[i]);
    }
    free(dfs.M);

    return 0;
}