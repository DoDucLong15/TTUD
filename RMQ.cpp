#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
int a[N], M[20][N];

void solve()
{
    for(int i=0; i<n; i++) M[0][i] = i;

    for(int i=1; (1<<i) <= n; i++) {
        for(int j=0; j+(1<<i)<=n; j++) {
            if(a[M[i-1][j]] < a[M[i-1][j+(1<<(i-1))]]) {
                M[i][j] = M[i-1][j];
            }
            else M[i][j] = M[i-1][j+(1<<(i-1))];
        }
    }
}

int RMQ(int i, int j)
{
    int k = (int)log2(j-i+1);
    if(a[M[k][i]] <= a[M[k][j-(1<<k)+1]]) {
        return a[M[k][i]];
    }
    else return a[M[k][j-(1<<k)+1]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    solve();
    scanf("%d", &m);
    int i, j, sum=0;
    for(int x=0; x<m; x++) {
        scanf("%d%d", &i, &j);
        sum += RMQ(i, j);
    }
    printf("%d\n", sum);

    return 0;
}
