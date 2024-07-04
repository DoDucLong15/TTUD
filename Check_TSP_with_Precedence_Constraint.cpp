#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int n;
int x[MAX];
int d[MAX][MAX];
int m;
bool conflict[MAX][MAX];

bool check(int a, int k)
{
    for(int i=1; i<k; i++) {
        if(conflict[a][x[i]]) return false;
    }
    return true;
}

int solve()
{
    int sum = 0;
    for(int i=2; i<=n; i++) {
        if(check(x[i], i)) {
            sum += d[x[i-1]][x[i]];
        }
        else return -1;
    }
    sum += d[x[n]][x[1]];
    return sum;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &x[i]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) scanf("%d", &d[i][j]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int a, b;
         scanf("%d%d", &a, &b);
        conflict[a][b] = true; //a truoc b
    }
    cout << solve() << "\n";

    return 0;
}
