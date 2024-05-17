#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
int k, n;

int C(int k, int n)
{
    int c[n+1][n+1] = {0};
    for(int j=0; j<=n; j++) c[0][j] = 1;
    for(int i=1; i<=n; i++) c[i][0] = 0;
    for(int j=1; j<=n; j++) {
        for(int i=1; i<=j; i++) {
            c[i][j] = (c[i-1][j-1] + c[i][j-1])%N;
        }
    }
    return c[k][n];
}

int main()
{
    scanf("%d%d", &k, &n);
    cout << C(k,n) << "\n";

    return 0;
}
