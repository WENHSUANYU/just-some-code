#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string>

using namespace std;
#define N 4
#define N2 16
#define LIMIT 100

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};
const char dir[4] = {'r', 'u', 'l', 'd'};


struct Puzzle {
    int f[N2];
    int space;
    int MD;
};

class Puzzle_IDA{
    public:
        int MDT[N2][N2];
        Puzzle state;
        int limit;
        int path[LIMIT];

        Puzzle_IDA()
        {
            
        }

        int getAllMD(Puzzle pz) {
            int sum = 0;
            for (int i = 0; i < N2; i++) {
                if (pz.f[i] != N2)
                    sum += MDT[i][pz.f[i] - 1];
            }
            return sum;
        }

        /*
        * position(index) | Final value     
        * 0 1 2 3         | 1 2 3 4
        * 4 5 6 7         | 5 6 7 8
        * 8 9 10 11       | 9 10 11 12
        * 12 13 14 15     | 13 14 15 0(16)
        */
        bool dfs(int depth, int prev) {

            if (state.MD == 0)
                return true;

            // 目前深度加上曼哈頓距離(即到達最終狀態的最小成本)大於限制深度，進行剪枝(pruning)
            if (depth + state.MD > limit)
                return false;

            int sx = state.space / N;
            int sy = state.space % N;

            Puzzle tmp;
            for (int r = 0; r < 4; r++) {
                int tx = sx + dx[r];
                int ty = sy + dy[r];
                if (tx < 0 || ty < 0 || tx >= N || ty >= N)
                    continue;
                if (max(prev, r) - min(prev, r) == 2)
                    continue;
                tmp = state;
                /* 計算曼哈頓距離的增減，並將兩塊拼圖進行交換(其中一塊是包含0(16)的拼圖)
                *  (非0的那塊拼圖)先減去從原本位置到正確位置的曼哈頓距離，
                *  其中第一個[]是以0的交換後新座標表示，
                *  第二個[]則表示到達正確位置(透過上圖可知是值減去1)。
                *  (非0的那塊拼圖)再加上交換後新位置到正確位置的曼哈頓距離，
                *  其中第一個[]是以0的交換前座標表示，
                *  第二個[]則表示到達正確位置(與前面相同)。
                */
                state.MD -= MDT[tx * N + ty][state.f[tx * N + ty] - 1];
                state.MD += MDT[sx * N + sy][state.f[tx * N + ty] - 1];
                swap(state.f[tx * N + ty], state.f[sx * N + sy]);
                state.space = tx * N + ty;
                if (dfs(depth + 1, r)) {
                    path[depth] = r;
                    return true;
                }
                state = tmp;
            }
            return false;
        }

        string iterative_deepening(Puzzle in) {
            // 計算現在拼圖的曼哈頓距離
            in.MD = getAllMD(in);
            for (limit = in.MD; limit <= LIMIT; limit++) {
                state = in;
                if (dfs(0, -100)) {
                    string ans = "";
                    for (int i = 0; i < limit; i++)
                        ans += dir[path[i]];
                    return ans;
                }
            }
            return "unsolvable";
        }
};

int main()
{
    Puzzle_IDA p;
    //建立曼哈頓距離表
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
            p.MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }

    Puzzle in;
    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            in.f[i] = N2;
            in.space = i;
        }
    }
    string ans = p.iterative_deepening(in);
    cout << ans.size() << endl;
    return 0;
}


