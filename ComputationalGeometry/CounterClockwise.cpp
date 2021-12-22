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

int ccw(Point p0, Point p1, Point p2)
{
    Vector a, b;
    a.p = p1 - p0;
    b.p = p2 - p0;
    if (cross(a, b) > EPS)
        return 0;
    if (cross(a,b) < -EPS)
        return 1;
    if (dot(a, b) < -EPS)
        return 2;
    if (norm(a) < norm(b))
        return 3;
    return 4;

}

int main(void)
{
    Point p0, p1;
    cin >> p0.x >> p0.y >> p1.x >> p1.y;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        Point p2;
        cin >> p2.x >> p2.y;
        int result = ccw(p0, p1, p2);
        switch (result) {
            case 0:
                cout << "COUNTER_CLOCKWISE" << endl;
                break;
            case 1:
                cout << "CLOCKWISE" << endl;
                break;
            case 2:
                cout << "ONLINE_BACK" << endl;
                break;
            case 3:
                cout << "ONLINE_FRONT" << endl;
                break;
            case 4:
                cout << "ON_SEGMENT" << endl;
                break;
        }
    }



    return 0;
}