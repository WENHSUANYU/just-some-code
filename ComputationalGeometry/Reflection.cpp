#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

typedef struct{
    double x;
    double y;
}Point;

typedef struct{
    Point A, B;
    double x = A.x - B.x;
    double y = A.y - B.y;

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
    Point tmp = {(projection_p.x - p.x) * 2.0, (projection_p.y - p.y) * 2.0};
    return {p.x + tmp.x, p.y + tmp.y};
}

double Reflection::dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

double Reflection::norm(Vector a)
{
    return a.x * a.x + a.y * a.y;
}

void Reflection::project(Segment s, Point p)
{
    Vector base;
    base.A = s.B;
    base.B = s.A;
    base.x = base.A.x - base.B.x;
    base.y = base.A.y - base.B.y;
    Vector point_p;
    point_p.A = p;
    point_p.B = s.A;
    point_p.x = point_p.A.x - point_p.B.x;
    point_p.y = point_p.A.y - point_p.B.y;
    double ratio = dot(point_p, base) / norm(base);
    projection_p = {s.A.x + base.x * ratio, s.A.y + base.y * ratio};
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