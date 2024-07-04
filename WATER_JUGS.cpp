#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int a, b, c;
map<pii,int> mp;

struct Jug
{
    int m, n;
    int step;
    Jug(int _m, int _n, int _step)
    {
        m = _m; n = _n; step = _step;
    }
};

int solve()
{
    queue<Jug> q;
    q.push(Jug(0,0,0));
    mp[make_pair(0,0)] = 1;
    while(!q.empty()) {
        auto x = q.front(); q.pop();
        if((x.m==0 && x.n==c) || (x.m==c && x.n==0)) return x.step;
        //lam day binh
        if(x.m < a && mp[make_pair(a, x.n)] == 0) {
            q.push(Jug(a, x.n, x.step+1));
            mp[make_pair(a, x.n)] = 1;
        }
        if(x.n < b && mp[make_pair(x.m,b)] == 0) {
            q.push(Jug(x.m, b, x.step+1));
            mp[make_pair(x.m,b)] = 1;
        }
        //lam rong binh
        if(x.m > 0 && mp[make_pair(0, x.n)] == 0) {
            q.push(Jug(0, x.n, x.step+1));
            mp[make_pair(0, x.n)] = 1;
        }
        if(x.n > 0 && mp[make_pair(x.m, 0)] == 0) {
            q.push(Jug(x.m, 0, x.step+1));
            mp[make_pair(x.m, 0)] = 1;
        }
        //swap
        if(x.m > 0) {
            if(x.n < b) {
                int d = b - x.n;
                if(d <= x.m && mp[make_pair(x.m-d,b)] == 0) {
                    q.push(Jug(x.m-d, b, x.step+1));
                    mp[make_pair(x.m-d,b)] = 1;
                }
                else if(mp[make_pair(0, x.n+x.m)] == 0) {
                    q.push(Jug(0, x.n + x.m, x.step+1));
                    mp[make_pair(0, x.n+x.m)] = 1;
                }
            }
        }
        if(x.n > 0) {
            if(x.m < a) {
                int d = a - x.m;
                if(d <= x.n && mp[make_pair(a, x.n-d)] == 0) {
                    q.push(Jug(a, x.n - d, x.step+1));
                    mp[make_pair(a, x.n-d)] = 1;
                }
                else if(mp[make_pair(x.m+x.n, 0)] == 0) {
                    q.push(Jug(x.m + x.n, 0, x.step+1));
                    mp[make_pair(x.m+x.n, 0)] = 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    cout << solve() - 1 << "\n";

    return 0;
}
