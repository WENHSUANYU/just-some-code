#include<iostream>
#include<cmath>
#include<iomanip>
//#define EPS (1e-8)

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

double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

double norm(Vector a)
{
    return a.x * a.x + a.y * a.y;
}

Point project(Segment s, Point p)
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
    return {s.A.x + base.x * ratio, s.A.y + base.y * ratio};
}

int main(void)
{
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Segment S = {.A = p1, .B = p2};
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        Point p;
        cin >> p.x >> p.y;
        Point result = project(S, p);
        cout << fixed;
        cout << setprecision(10);
        cout << result.x << " " << result.y << endl;

    }

    return 0;
}