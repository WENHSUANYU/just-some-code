#include<iostream>
#include<cmath>
#include<cassert>
#include<iomanip>
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

typedef struct Circle{
    Point c;
    double r;
    Circle(Point c, double r): c(c), r(r)
    {

    }
}Circle;

double norm(Vector a)
{
    return a * a.p;
}

double abs(Vector a)
{
    return sqrt(norm(a));
}

bool intersect(Circle c1, Circle c2)
{
    Vector c12;
    c12.p = c2.c - c1.c;
    double d = abs(c12);
    if (d <= c1.r + c2.r)
        return true;
    else
        return false;
}

double arg(Vector v)
{
    return atan2(v.p.y, v.p.x);
}

Point polar(double a, double rad)
{
    return {a * cos(rad), a * sin(rad)};
}

pair<Point, Point> getCrossPoints(Circle c1, Circle c2)
{
    assert(intersect(c1, c2));
    Vector tmp;
    tmp.p = c2.c - c1.c;
    double d = abs(tmp);
    double alpha = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(tmp);
    return make_pair(c1.c + polar(c1.r, t + alpha), c1.c + polar(c1.r, t - alpha));
}

int main(void)
{
    Point p1, p2;
    double r1, r2;
    cin >> p1.x >> p1.y >> r1;
    cin >> p2.x >> p2.y >> r2;
    Circle c1(p1, r1);
    Circle c2(p2, r2);
    pair<Point, Point> result = getCrossPoints(c1, c2);
    cout << fixed;
    cout << setprecision(7);
    cout << result.first.x << " " << result.first.y << " ";
    cout << result.second.x << " " << result.second.y << endl;

    return 0;
}