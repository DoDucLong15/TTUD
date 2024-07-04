#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

double distance(Point &a, Point &b)
{
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    return sqrt(1LL * x*x + 1LL * y*y);
}

double cross_product(Point &O, Point &A, Point &B)
{
    long long xa = A.x - O.x;
    long long ya = A.y - O.y;
    long long xb = B.x - O.x;
    long long yb = B.y - O.y;
    return 1LL * xa*yb - 1LL * ya*xb;
}

int main()
{
    Point O(2,5);
    Point A(5,6);
    Point B(1,1);
    double sin = cross_product(O, A, B)/(distance(O,A)*distance(O,B));
    cout << sin << "\n";

    return 0;
}

