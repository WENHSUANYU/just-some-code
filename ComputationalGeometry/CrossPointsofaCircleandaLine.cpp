#include<iostream>
#include<cmath>
#include<iomanip>
#include<cassert>
#include<utility>
#define EPS (1e-10)
using namespace std;

typedef struct Point{
    double x;
    double y;
    Point operator+(const Point &p)
    {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point &p)
    {
        return {x - p.x, y - p.y};
    }
    Point operator/(const double k)
    {
        return {x / k, y / k};
    }
    Point operator*(const Point &p)
    {
        return {x * p.x, y * p.y};
    }
    Point operator*(const double k)
    {
        return {x * k, y * k};
    }
}Point;

typedef struct Circle{
    Point c;
    double r;
    Circle(Point c, double r): c(c), r(r)
    {

    }
}Circle;


typedef struct{
    Point p;
    double operator*(const Point &q)
    {
        return p.x * q.x + p.y * q.y;
    }
    Point operator*(const double k)
    {
        return p = {p.x * k, p.y * k};
    }
}Vector;

typedef struct{
    Point p, p1;
}Segment;

typedef Segment Line;

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

bool intersect(Circle c, Line l)
{
    double numerator = abs((l.p1.x - l.p.x) * (l.p.y - c.c.y) - (l.p.x - c.c.x) * (l.p1.y - l.p.y));
    Vector v;
    v.p = l.p1 - l.p;
    double denominator = abs(v);
    return (numerator / denominator <= c.r) ? (1) : (0);
}

Point project(Segment s, Point p)
{
    Vector base;
    base.p = s.p1 - s.p;
    Vector point_p;
    point_p.p = p - s.p;
    double ratio = dot(point_p, base) / norm(base);
    base.p = base * ratio;
    return s.p + base.p;
}

pair<Point, Point> getCrossPoints(Circle c, Line l)
{
    assert(intersect(c, l));
    Point proj_point = project(l, c.c);
    Vector toP1;
    toP1.p = l.p1 - l.p; 
    Vector e;
    e.p = (l.p1 - l.p) / abs(toP1);
    Vector toProj;
    toProj.p = proj_point - c.c;
    double base = sqrt(c.r * c.r - norm(toProj));
    return make_pair(proj_point + e.p * base, proj_point - e.p * base);
}

int main(void)
{
    Point center;
    double radius;
    cin >> center.x >> center.y >> radius;
    Circle c(center, radius);
    int q;
    cin >> q;
    Line l;
    for (int i = 0; i < q; i++) {
        cin >> l.p.x >> l.p.y >> l.p1.x >> l.p1.y;
        pair<Point, Point> result = getCrossPoints(c, l);
        cout << result.first.x << " " << result.first.y << " ";
        cout << result.second.x << " " << result.second.y << endl;
    }

    return 0;
}