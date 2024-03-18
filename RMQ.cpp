#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
int n, a[MAX], b[20][MAX], m;

void preprocessing()
{
    for(int k=0; k<n; k++) b[0][k] = k;
    for(int i=1; (1<<i)<=n; i++)
        for(int j=0; j+(1<<i)-1 < n; j++)
            if(a[b[i-1][j]] < a[b[i-1][j+(1<<(i-1))]]) b[i][j] = b[i-1][j];
            else b[i][j] = b[i-1][j+(1<<(i-1))];
}

int RMQ(int i, int j)
{
    int k = floor(log2(j-i+1));
    if(a[b[k][i]] < a[b[k][j-(1<<k)+1]]) return a[b[k][i]];
    else return a[b[k][j-(1<<k)+1]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d", &n);
    for(int k=0; k<n; k++) {
        scanf("%d", &a[k]);
    }
    scanf("%d", &m);
    int sum = 0;
    preprocessing();
    for(int k=0; k<m; k++) {
        int i, j;
        scanf("%d%d", &i, &j);
        sum += RMQ(i, j);
    }

    cout << sum << "\n";
    return 0;
}
