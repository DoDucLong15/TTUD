#include <bits/stdc++.h>
using namespace std;

int n, c[25][25];
int c_min = INT_MAX;
int f = 0, f_min = INT_MAX;
bool mark[25];
int road[25];

bool check(int i)
{
    if(mark[i]) return false;
    return true;
}

void GhiNhan()
{
    int d = f + c[road[n]][1];
    f_min = min(f_min, d);
}

void Try(int k)
{
    for(int i=2; i<=n; i++) {
        if(check(i)) {
            mark[i] = true;
            road[k] = i;
            f += c[road[k-1]][i];
            if(k == n) GhiNhan();
            else if(f + c_min*(n-k+1) < f_min) Try(k+1);
            mark[i] = false;
            f -= c[road[k-1]][i];
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) c_min = min(c_min, c[i][j]);
        }
    road[1] = 1;
    Try(2);
    cout << f_min << "\n";

    return 0;
}
