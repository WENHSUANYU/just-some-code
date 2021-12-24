#include<iostream>
#include<vector>
#include<set> // red-black tree -> balanced binary search tree
#include<algorithm>
#include<cmath>
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3
using namespace std;

typedef struct Point{
    double x;
    double y;
    bool operator<(Point &p)
    {
        return (x < p.x) ? (true) : (x == p.x ? (y > p.y ? true : false) : false);
    }
}Point;

typedef struct{
    Point p1, p2;
}Segment;

class EndPoint {
    public:
        Point p;
        int seg, st; //segment id, Endpoint type
        EndPoint(){}
        EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {

        }
        bool operator<(const EndPoint &ep) const{
            if (p.y == ep.p.y) {
                return st < ep.st;
            } else {
                return p.y < ep.p.y;
            }
        }
};

int manhattanIntersection(vector<Segment> S, int n)
{
    EndPoint *ep = new EndPoint[2 * n];
    for (int i = 0, k = 0; i < n; i++) {
        //Adjust the endpoints to ensure that p1 is greater than p2
        if (S[i].p1.y == S[i].p2.y) {
            if (S[i].p1.x > S[i].p2.x) {
                swap(S[i].p1, S[i].p2);
            }
        } else if (S[i].p1.y > S[i].p2.y) {
            swap(S[i].p1, S[i].p2);
        }
        //horizontal line
        if (S[i].p1.y == S[i].p2.y) {
            ep[k++] = EndPoint(S[i].p1, i, LEFT);
            ep[k++] = EndPoint(S[i].p2, i, RIGHT);            
        } else {
            ep[k++] = EndPoint(S[i].p1, i, BOTTOM);
            ep[k++] = EndPoint(S[i].p2, i, TOP);
        }
    
    }
    sort(ep, ep + (2 * n));

    set<int> BT;
    BT.insert(10000001); //mark
    int cnt = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (ep[i].st == TOP) {
            BT.erase(ep[i].p.x);
        } else if (ep[i].st == BOTTOM) {
            BT.insert(ep[i].p.x);
        } else if (ep[i].st == LEFT) {
            auto b = BT.lower_bound(S[ep[i].seg].p1.x); //O(logn) >=
            auto c = BT.upper_bound(S[ep[i].seg].p2.x); //O(logn) >
            cnt += distance(b, c);
        }
    }

    return cnt;
}

int main(void)

{
    int n;
    cin >> n;
    vector<Segment> S;
    S.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i].p1.x >> S[i].p1.y >> S[i].p2.x >> S[i].p2.y;
    }
    cout << manhattanIntersection(S, n);

    return 0;
}