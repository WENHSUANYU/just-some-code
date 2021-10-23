/*
* Input
* n: int
* Output
* coordinates x, y: double double 
*/
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
using namespace std;

typedef struct {
    double x;
    double y;
}Point;


Point rotation_matrix(Point s, Point t)
{
    Point u;
    double theta = M_PI * 60.0 / 180.0;
    u.x = (t.x - s.x) * cos(theta) - (t.y - s.y) * sin(theta) + s.x;
    u.y = (t.x - s.x) * sin(theta) + (t.y - s.y) * cos(theta) + s.y;
    return u;
}

void koch(int n, Point a, Point b)
{
    if (n == 0)
        return;
    Point s, t, u;
    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u = rotation_matrix(s,t);
    koch(n-1,a,s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(n-1,s,u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(n-1,u,t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(n-1,t,b);

}

int main() {
    ios_base::sync_with_stdio(false);
    Point a, b;
    int n;
    cin >> n;
    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;

    printf("%.8f %.8f\n", a.x, a.y);
    koch(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);
    return 0;
}