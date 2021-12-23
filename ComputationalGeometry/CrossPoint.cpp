#include<iostream>
#include<cmath>
#include<iomanip>
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
}Point;

typedef struct{
    Point p;
    double operator*(Point &q)
    {
        return p.x * q.x + p.y * q.y;
    }
    Point operator*(double k)
    {
        return p = {p.x * k, p.y * k};
    }
}Vector;

typedef struct{
    Point p, p1;
}Segment;

double dot(Vector a, Vector b)
{
    return a * b.p;
}

double cross(Vector a, Vector b)
{
    return a.p.x * b.p.y - a.p.y * b.p.x;
}

double norm(Vector a)
{
    return a * a.p;
}

double abs(Vector a)
{
    return sqrt(norm(a));
}

double getDistanceLP(Segment s, Point p)
{
    Vector toP, toS;
    toP.p = p - s.p;
    toS.p = s.p1 - s.p;
    return abs(cross(toS, toP) / abs(toS));
}

Point getCrossPoint(Segment s1, Segment s2)
{
    Vector v;
    v.p = s1.p1 - s1.p;
    double d = getDistanceLP(s2, s1.p);
    double d1 = getDistanceLP(s2, s1.p1);
    double ratio = d / (d + d1);
    v.p = v * ratio;
    return s1.p + v.p;
}

int main(void)
{
    int q;
    cin >> q;
    Segment s1, s2;
    for (int i = 0; i < q; i++) {
        cin >> s1.p.x >> s1.p.y >> s1.p1.x >> s1.p1.y;
        cin >> s2.p.x >> s2.p.y >> s2.p1.x >> s2.p1.y;
        Point result = getCrossPoint(s1, s2);
        cout << fixed;
        cout << setprecision(10);
        cout << result.x << " " << result.y << endl;
    }
    
    return 0;
}