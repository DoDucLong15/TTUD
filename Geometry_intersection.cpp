#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    Point(int x, int y): x(x), y(y) {}
};

struct Line
{
    int a, b, c;
};

void makeLine(Point &A, Point& B, Line& L)
{
    L.a = A.y - B.y;
    L.b = B.x - A.x;
    L.c = A.x*B.y - A.y*B.x;
}

void intersection(Line& L1, Line& L2)
{
    double x = (L2.c*L1.b - L1.c*L2.b)*1.0/(L1.a*L2.b - L2.a*L1.b);
    double y = (L1.c*L2.a - L2.c*L1.a)*1.0/(L1.a*L2.b - L2.a*L1.b);
    cout << "Giao diem = (" << x << "," << y << ")" << endl;
}

int main()
{
    Point A(3,1); Point B(6,4); Line LAB;
    Point C(2,5); Point D(7,0); Line LCD;
    makeLine(A,B,LAB); makeLine(C,D,LCD);
    intersection(LAB, LCD);

    return 0;
}
