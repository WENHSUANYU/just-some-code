#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define EPS (1e-10)
using namespace std;

typedef struct Point{
    double x;
    double y;
    Point operator+(Point &p)
    {
        return {x + p.x, y + p.y};
    }
    Point operator-(Point &p)
    {
        return {x - p.x, y - p.y};
    }
    double operator*(Point &p)
    {
        return x * p.x + y * p.y;
    }
    bool operator<(Point &p)
    {
        return (x < p.x) ? (true) : (x == p.x ? (y > p.y ? true : false) : false);
    }
}Point;

typedef vector<Point> Polygon;
typedef Point Vector;

template<typename T>
double norm(T a)
{
    return a * a;
}
template<typename T>
double abs(T a)
{
    return sqrt(norm(a));
}

template<typename T>
double dot(T a, T b)
{
    return a * b;
}

template<typename T>
double cross(T a, T b)
{
    return a.x * b.y - a.y * b.x;
}

int ccw(Point p0, Point p1, Point p2)
{
    Vector a, b;
    a = p1 - p0;
    b = p2 - p0;
    if (cross(a, b) > EPS)
        return 1;
    if (cross(a, b) < -EPS)
        return -1;
    if (dot(a, b) < -EPS)
        return 2;
    if (norm(a) < norm(b))
        return -2;
    return 0;
}
//Andrew's algorithm
//time complexity: O(nlogn)
Polygon andrewScan(Polygon s)
{
    Polygon u, l;
    if (s.size() < 3)
        return s;
    //O(nlogn)
    sort(s.begin(), s.end());

    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);

    for(int i = 2; i < (int)s.size(); i++) {
        for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) == 1; n--) {
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    for(int i = s.size() - 3; i >= 0; i--) {
        for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) == 1; n--) {
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    reverse(l.begin(), l.end());

    for (int i = u.size() - 2; i > 0; i--) {
        l.push_back(u[i]);
    }
    return l;
}

int main(void)
{
    int n;
    cin >> n;
    Polygon p;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    Polygon result = andrewScan(p);
    cout << result.size() << endl;
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i].x << " " <<result[i].y << endl;
    }
    return 0;
}