#include<iostream>
#include<cmath>
#define EPS (1e-10) //epislon
#define equals(a, b) (fabs((a) - (b)) < EPS)
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

double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}

bool isOrthogonal(Vector a, Vector b)
{
    return equals(dot(a, b), 0.0);
}

bool isParallel(Vector a, Vector b)
{
    return equals(cross(a, b), 0.0);
}

int main(void)
{
    Point p[4];
    int n;
    cin >> n;
    Vector v[2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> p[j].x >> p[j].y;
        }
        v[0].x = p[1].x - p[0].x;
        v[0].y = p[1].y - p[0].y;
        v[1].x = p[3].x - p[2].x;
        v[1].y = p[3].y - p[2].y;

        if (isParallel(v[0], v[1]))
            cout << "Parallel" << endl;
        else if (isOrthogonal(v[0], v[1]))
            cout << "Orthogonal" << endl;
        else
            cout << "None";

    }
    return 0;
}