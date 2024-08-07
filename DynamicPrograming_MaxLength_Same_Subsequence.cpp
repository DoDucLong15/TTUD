#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int n, m;
int x[MAX], y[MAX];
int mem[MAX][MAX];

int LCS(int i, int j)
{
    if(i == 0 || j == 0) return 0;
    if(mem[i][j] != -1) return mem[i][j];

    int res = 0;
    res = max(res, LCS(i-1, j));
    res = max(res, LCS(i, j-1));
    if(x[i] == y[j]) res = max(res, 1+LCS(i-1, j-1));
    mem[i][j] = res;
    return res;
}

int main()
{
    memset(mem, -1, sizeof(mem));
    n = 5;
    m = 4;
    for(int i=1; i<=n; i++) {
        x[i] = i + 1;
    }
    for(int i=1; i<=m; i++) {
        y[i] = i;
    }
    cout << LCS(n, m) << "\n";

    return 0;
}
