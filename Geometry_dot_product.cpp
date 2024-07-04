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

double dot_product(Point &O, Point &A, Point &B)
{
    long long xa = A.x - O.x;
    long long ya = A.y - O.y;
    long long xb = B.x - O.x;
    long long yb = B.y - O.y;
    return 1LL * xa*xb + 1LL * ya*yb;
}

int main()
{
    Point O(2,5);
    Point A(5,6);
    Point B(6,2);
    double cos = dot_product(O, A, B)/(distance(O,A)*distance(O,B));
    cout << cos << "\n";

    return 0;
}
