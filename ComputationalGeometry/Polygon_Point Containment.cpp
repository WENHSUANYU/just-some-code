#include<iostream>
#include<vector>
#include<cmath>
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
    double operator*(const Point &p)
    {
        return x * p.x + y * p.y;
    }
}Point;

typedef vector<Point> Polygon;

typedef struct Vector{
    double x;
    double y;
    double operator*(const Vector &q)
    {
        return this->x * q.x + this->y * q.y;
    }
    Vector operator*(double k)
    {
        return {this->x * k, this->y * k};
    }
}Vector;

double norm(Vector a)
{
    return a * a;
}

double abs(Vector a)
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

int contains(Polygon p, Point pt)
{
    int n = p.size();
    bool flag = false;
    for (int i = 0; i < n; i++) {
        Point a = p[i] - pt;
        Point b = p[i + 1 % n] - pt;
        if (abs(cross(a, b)) < EPS && dot(a, b) < EPS)
            return 1;
        if (a.y > b.y)
            swap(a, b);
        if (a.y < EPS && b.y > EPS && cross(a, b) > EPS)
            flag = !flag;
    }
    return (flag ? 2 : 0);
}


int main(void)
{

    int n;
    cin >> n;
    Polygon p;
    for (int i = 0; i < n; i++) {
        static double x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    int q;
    cin >> q;
    Point pt;
    for (int i = 0; i < q; i++) {
        cin >> pt.x >> pt.y;
        cout << contains(p, pt) << endl;
    }

    return 0;
}