#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
int n, k1, k2;

int solve()
{
    int s0[n+1], s1[n+1];
    for(int i=1; i<=n; i++) {
        s0[i] = 0;
        s1[i] = 0;
    }
    s0[1] = 1; s0[0] = 1; s1[k1] = 1;
    for(int i=k1+1; i<=n; i++) {
        s0[i] = s1[i-1];
        s1[i] = 0;
        for(int j=k1; j<=k2; j++) {
            if(i-j >= 0) s1[i] += s0[i-j];
        }
    }
    return (s0[n] + s1[n])%M;
}

int main()
{
    scanf("%d%d%d", &n, &k1, &k2);
    cout << solve() << "\n";

    return 0;
}
