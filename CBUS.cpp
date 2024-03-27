#include <bits/stdc++.h>
using namespace std;

const int MAX = 25;
int n, k, load = 0, f = 0, cmin=INT_MAX, f_min = INT_MAX;
int c[MAX][MAX], road[MAX];
bool mark[MAX];

bool check(int v)
{
    if(mark[v]) return false;
    if(v > n) {
        if(!mark[v-n]) return false;
    }
    else if(load + 1 > k) return false;
    return true;
}

void GhiNhan()
{
    if((f + c[road[2*n]][0]) < f_min) f_min = f + c[road[2*n]][0];
}

void Try(int k)
{
    for(int v=1; v<=2*n; v++) {
        if(check(v)) {
            road[k] = v;
            if(v<=n) load++;
            else load--;
            mark[v] = true;
            f += c[road[k-1]][v];
            if(k==2*n) GhiNhan();
            else if(f + (2*n+1-k)*cmin < f_min) Try(k+1);
            if(v<=n) load--;
            else load++;
            mark[v] = false;
            f -= c[road[k-1]][v];
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) cmin = min(cmin, c[i][j]);
        }

    road[0] = 0;
    Try(1);

    cout << f_min << "\n";

    return 0;
}
