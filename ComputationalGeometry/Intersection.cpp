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

//Segment
int main(void)
{
    int q;
    cin >> q;
    Point p1, p2, p3, p4;
    for (int i = 0; i < q; i++) {
        cin >> p1.x >> p1.y;
        cin >> p2.x >> p2.y;
        cin >> p3.x >> p3.y;
        cin >> p4.x >> p4.y;
        if (intersect(p1, p2, p3, p4))
            cout << "1" << endl;
        else
            cout << "0" << endl;   

    }



    return 0;
}