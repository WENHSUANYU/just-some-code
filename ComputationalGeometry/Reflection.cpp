#include<iostream>
#include<cmath>
#include<iomanip>
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
    Point operator*(double k)
    {
        return {x * k, y * k};
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
    Point A, B;
}Segment;

class Reflection{

    public:
        Point p1, p2;
        Point projection_p;
        Segment s;
        Reflection(Point p1, Point p2): p1(p1), p2(p2){}
        void project(Segment, Point);
        double dot(Vector, Vector);
        double norm(Vector);
        Point reflect(Point);

};

Point Reflection::reflect(Point p)
{
    Point tmp = (projection_p - p) * 2.0;
    return p + tmp;
}

double Reflection::dot(Vector a, Vector b)
{
    return a * b.p;
}

double Reflection::norm(Vector a)
{
    return a * a.p;
}

void Reflection::project(Segment s, Point p)
{
    Vector base;
    base.p = s.B - s.A;
    Vector AtoP;
    AtoP.p = p - s.A;
    double ratio = dot(AtoP, base) / norm(base);
    base.p = base * ratio;
    projection_p = s.A + base.p;

}

int main(void)
{
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Reflection R(p1, p2);
    R.s = {.A = p1, .B = p2};
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        Point p;
        cin >> p.x >> p.y;
        R.project(R.s, p);
        Point reflection_point = R.reflect(p);
        cout << fixed;
        cout << setprecision(10);
        cout << reflection_point.x << " " << reflection_point.y << endl;
    }

    return 0;
}