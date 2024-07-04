#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;

struct Point {
    int x, y;
    Point():x(0),y(0){}
    Point(int x, int y) : x(x), y(y) {}
};

Point P[N];
int n;
vector<Point> C;
Point O;

long long dist2(Point &a, Point &b) {
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    return 1LL * x*x + 1LL * y*y;
}

long long cross_product(Point &O, Point &A, Point &B) {
    //tich co huong 2 vector (O,A) x (O,B)
    long long xa = A.x - O.x; long long ya = A.y - O.y;
    long long xb = B.x - O.x; long long yb = B.y - O.y;
    return 1LL * xa * yb - 1LL * ya * xb;
}

bool cmp(Point& A, Point& B){
    long long cp = cross_product(O,A,B);
    return cp == 0 ? dist2(O,A) < dist2(O,B) : cp > 0;
}

int ccw(Point &a, Point &b, Point &c) {
    long long cp = cross_product(a, b, c);
    return cp == 0 ? 0 : (cp < 0 ? -1 : 1);
}

bool same_side(Point &a, Point &b, Point &c, Point &d) {
    // return true if c and d are in the same side of the line (a,b)
    int sc = ccw(a, b, c);
    int sd = ccw(a, b, d);
    return sc * sd >= 0;
}

void computeConvexHull(Point* P, int n){
    C.clear(); int k = 0;
    for(int i = 1; i < n; i++){
        if(P[i].y < P[k].y ||
        P[i].y == P[k].y && P[i].x < P[k].x) k = i;
    }
    swap(P[0],P[k]);// let P[0] be the lowest point
    O = P[0];// update goc
    sort(P+1,P+n,cmp);
    C.push_back(P[0]); C.push_back(P[1]);
    for(int i = 2; i < n; i++){
        while(C.size() > 1 && ccw(C[C.size()-2], C[C.size()-1],P[i]) <= 0) C.pop_back();
        C.push_back(P[i]);
    }
}

int checkInSideConvexHull(vector<Point> P, Point& T) {
    int last = P.size() - 1;
    if (same_side(P[0], P[1], P[last], T) && same_side(P[0], P[last], P[1], T)) {
        int l = 1; int r = P.size() - 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (same_side(P[0], P[mid], P[last], T)) l = mid;
            else r = mid;
        }
        if (!same_side(P[l], P[r], P[0], T)) return 0;
        else return 1;
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d%d",&(P[i].x),&(P[i].y));
    }
    computeConvexHull(P,n);
    int res = 1;
    if(C.size() != n) res = 0;
    int K;
    scanf("%d",&K);
    for(int k = 1; k <= K; k++){
        int x,y; scanf("%d%d",&x,&y);
        Point p(x,y);
        if(res == 1) res = checkInSideConvexHull(C,p);
        printf("%d\n",res);
    }
    return 0;
}
