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

int ccw(Point p0, Point p1, Point p2)
{
    Vector a, b;
    a.p = p1 - p0;
    b.p = p2 - p0;
    if (cross(a, b) > EPS)
        return 1;
    if (cross(a,b) < -EPS)
        return -1;
    if (dot(a, b) < -EPS)
        return 2;
    if (norm(a) < norm(b))
        return -2;
    return 0;

}
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && 
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

double getDistanceLP(Segment s, Point p)
{
    Vector toP, toS;
    toP.p = p - s.p;
    toS.p = s.p1 - s.p;
    return abs(cross(toS, toP) / abs(toS));
}

double getDistanceSP(Segment s, Point p)
{
    Vector toP, toS;
    toS.p = s.p1 - s.p;
    toP.p = p - s.p;
    if (dot(toP, toS) < 0.0)
        return abs(toP);
    toS.p = s.p - s.p1;
    toP.p = p - s.p1;
    if (dot(toP, toS) < 0.0)
        return abs(toP);
    return getDistanceLP(s, p);
}

double getDistence(Segment s1, Segment s2)
{
    if (intersect(s1.p, s1.p1, s2.p, s2.p1))
        return 0.0;
    return min(min(getDistanceSP(s1, s2.p), getDistanceSP(s1, s2.p)), min(getDistanceSP(s2, s1.p), getDistanceSP(s2, s1.p1)));
}

int main(void)
{
    Segment s1, s2;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s1.p.x >> s1.p.y >> s1.p1.x >> s1.p1.y;
        cin >> s2.p.x >> s2.p.y >> s2.p1.x >> s2.p1.y;
        cout << fixed;
        cout << setprecision(10);
        cout << getDistence(s1, s2) << endl;
    }

    return 0;
}