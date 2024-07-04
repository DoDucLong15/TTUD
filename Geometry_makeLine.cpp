#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

struct Line
{
    int a, b, c;
};

void makeLine(Point& A, Point &B, Line& L)
{
    L.a = A.y - B.y;
    L.b = B.x - A.x;
    L.c = A.x * B.y - A.y * B.x;
}

int main()
{
    Point A(5,6);
    Point B(6,2);
    Line L;
    makeLine(A,B,L);
    cout << L.a << "x" << " + " << L.b << "y + " << L.c << " = 0\n";

    return 0;
}

