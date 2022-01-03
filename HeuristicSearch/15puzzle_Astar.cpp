#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#include<queue>
#define N 4
#define N2 16
using namespace std;
#define abs(n) (((n) >> 31) ^ (n)) - ((n) >> 31)
static const int dx[4] = {0, -1, 0, 1};
static const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'r', 'u', 'l', 'd'};

typedef struct Puzzle{
    int f[N2];
    int space;
    int MD;
    int cost;
    bool operator< (const Puzzle &p) const 
    {
        for (int i = 0; i < N2; i++) {
            if (f[i] == p.f[i])
                continue;
            return f[i] < p.f[i];
        }
        return false;
    }

}Puzzle;

typedef struct State{
    Puzzle puzzle;
    int estimated;
    bool operator<(const State &s) const {
        return estimated > s.estimated; 
    }
}State;

class Puzzle_Astar{

    public:
        int MDT[N2][N2];

        Puzzle_Astar()
        {

        }

        int getAllMD(Puzzle pz) {
            int sum = 0;
            for (int i = 0; i < N2; i++) {
                if(pz.f[i] == N2)
                    continue;
                sum += MDT[i][pz.f[i] - 1];
            }

            return sum;
        }

        int astar(Puzzle in)
        {
            priority_queue<State> PQ;
            in.MD = getAllMD(in);
            in.cost = 0;
            map<Puzzle, bool> V;
            Puzzle u, v;
            State initial;
            initial.puzzle = in;
            initial.estimated = getAllMD(in);
            PQ.push(initial);
            while(!PQ.empty()) {
                State st = PQ.top();
                PQ.pop();
                u = st.puzzle;
                if (u.MD == 0)
                    return u.cost;
                V[u] = true;

                int sx = u.space / N;
                int sy = u.space % N;

                for (int i = 0; i < N; i++) {
                    int tx = sx + dx[i];
                    int ty = sy + dy[i];

                    if (tx < 0 || ty < 0 || tx >= N || ty >= N)
                        continue;
                    v = u;

                    v.MD -= MDT[tx * N + ty][v.f[tx * N + ty] - 1];
                    v.MD += MDT[sx * N + sy][v.f[tx * N + ty] - 1];

                    swap(v.f[sx * N + sy], v.f[tx * N + ty]);
                    v.space = tx * N + ty;
                    if (!V[v]) {
                        v.cost++;
                        State new_state;
                        new_state.puzzle = v;
                        new_state.estimated = v.cost + v.MD;
                        PQ.push(new_state);
                    }
                }
            }

            return -1;
        }
};

int main(void)
{
    Puzzle_Astar p;
    Puzzle in;

    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
            p.MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }

    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            in.f[i] = N2;
            in.space = i;
        }
    }

    cout << p.astar(in) << endl;

    return 0;
}