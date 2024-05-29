#include <bits/stdc++.h>
using namespace std;

const int L = 1e4 + 5;
int n, m;
int X[L], Y[L];
int lis[L][L];

void resolve()
{
    for(int i=0; i<=n; i++) lis[i][0] = 0;
    for(int j=0; j<=m; j++) lis[0][j] = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            int res = 0;
            res = max(res, lis[i-1][j]);
            res = max(res, lis[i][j-1]);
            if(X[i] == Y[j]) res = max(res, 1 + lis[i-1][j-1]);
            lis[i][j] = res;
        }
    cout << lis[n][m] << "\n";
}

int main()
{
    memset(lis, -1, sizeof(lis));
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &X[i]);
    for(int i=1; i<=m; i++) scanf("%d", &Y[i]);
    resolve();

    return 0;
}
