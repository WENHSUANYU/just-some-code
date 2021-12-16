#include<iostream>
#include<vector>
#include<algorithm>
#define NIL -1
using namespace std;

//kD Tree (2D)

class Node {
    public:
        int location;
        //int p;
        int l, r;
        Node()
        {

        }
};

class Point {
    public:
        int id, x, y;
        Point()
        {

        }
        Point(int id, int x, int y): id(id), x(x), y(y) {

        }
    
        bool operator < (const Point &p) const {
            return id < p.id;
        }
        
        void print()
        {
            cout << id << endl;
        }

};

typedef struct range {
    int x1, x2, y1, y2;
}range;


bool lessX(const Point &p1, const Point &p2)
{
    return p1.x < p2.x;
}

bool lessY(const Point &p1, const Point &p2)
{
    return p1.y < p2.y;
}

class kDTree {
    public:
        int np;
        int n;
        Point *p;
        Node *T;

        kDTree(int n, int np){
            this->n = n;
            this->np = np;
            p = new Point[n]; //point set
            T = new Node[n]; // tree
            int x, y;
            for (int i = 0; i < n; i++) {
                cin >> x >> y;
                p[i] = {i, x, y};
                T[i].l = T[i].r = NIL;
            }
        }
        int  makekDTree(int l, int r, int depth)
        {
            if ( !(l < r))
                return NIL;
            int mid = (l + r) / 2;
            int t = np++;
            if ( depth % 2 == 0) {
                sort (p + l, p + r, lessX);
            } else {
                sort (p + l, p + r, lessY);
            }
            T[t].location = mid;
            T[t].l = makekDTree(l, mid, depth + 1);
            T[t].r = makekDTree(mid + 1, r, depth + 1);

            return t;
        }

        void find(int root, range r, int depth, vector<Point> &ans)
        {
            int x = p[T[root].location].x;
            int y = p[T[root].location].y;

            if (r.x1 <= x && x <= r.x2 && r.y1 <= y && y <= r.y2) {
                ans.push_back(p[T[root].location]);
            }

            if (depth % 2 == 0) {
                if (T[root].l != NIL)
                    if (r.x1 <= x)
                        find(T[root].l, r, depth + 1, ans);
                if (T[root].r != NIL)
                    if (x <= r.x2)
                        find(T[root].r, r, depth + 1, ans);
            } else {
                if (T[root].l != NIL)
                    if (r.y1 <= y)
                        find(T[root].l, r, depth + 1, ans);
                if (T[root].r != NIL)
                    if (y <= r.y2)
                        find(T[root].r, r, depth + 1, ans);
            }
        }

        ~kDTree(){
            delete [] p;
            delete [] T;
        }
};

int main(void){
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    range r;
    kDTree Tree(n,0);

    int root = Tree.makekDTree(0, n, 0);
    int q;
    vector<Point> ans;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> r.x1 >> r.x2 >> r.y1 >> r.y2;
        ans.clear();
        Tree.find(root, r, 0, ans);
        //overload operator '<'
        sort(ans.begin(), ans.end());
        for (int j = 0; (uint32_t)j < ans.size(); j++) {
            ans[j].print();
        }
        cout << endl;
    }
    
    return 0;
}