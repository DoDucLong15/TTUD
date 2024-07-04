#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

struct Point
{
    int x, y;
    Point(): x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

Point P[MAX];
int n;
vector<Point> C;

long long dist2(Point &A, Point &B)
{
    //tinh binh phuong khoang cach
    long long x = A.x - B.x;
    long long y = A.y - B.y;
    return 1LL * x*x + 1LL * y*y;
}

long long cross_product(Point &O, Point &A, Point &B)
{
    //Tinh tich co huong
    long long xa = A.x - O.x;
    long long ya = A.y - O.y;
    long long xb = B.x - O.x;
    long long yb = B.y - O.y;
    return 1LL * xa * yb - 1LL * ya * xb;
}

bool cmp(Point& A, Point &B)
{
    long long cp = cross_product(P[0], A, B);
    return (cp == 0) ? dist2(P[0],A) < dist2(P[0], B) : (cp > 0);
}

int ccw(Point &a, Point &b, Point &c)
{
    long long cp = cross_product(a, b, c);
    return (cp == 0) ? 0 : (cp < 0 ? -1 : 1);
}

void solve()
{
    //find lowest point
    int k = 0;
    for(int i=1; i<n; i++) {
        if(P[i].y < P[k].y || P[i].y == P[k].y && P[i].x < P[k].x) k = i;
    }
    swap(P[0], P[k]);
    sort(P+1,P+n,cmp);
    C.push_back(P[0]);
    C.push_back(P[1]);
    for(int i=2; i<n; i++) {
        while(C.size() > 1 && ccw(C[C.size()-2], C[C.size()-1], P[i]) <= 0) {
            C.pop_back();
        }
        C.push_back(P[i]);
    }
    cout << C.size() << "\n";
    for(int i=0; i<C.size(); i++) {
        cout << C[i].x << " " << C[i].y << "\n";
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &P[i].x, &P[i].y);
    }
    solve();

    return 0;
}
