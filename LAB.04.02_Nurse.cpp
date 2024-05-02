#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000;
int n, k1, k2;

void solve()
{
    int S0[MAX];
    int S1[MAX];
    for(int i=1; i<=n; i++) {
        S0[i] = 0;
        S1[i] = 0;
    }
    S0[1] = 1;
    S1[k1] = 1;
    S0[0] = 1; //linh canh
    for(int i=k1+1; i<=n; i++) {
        S0[i] = S1[i-1];
        S1[i] = 0;
        for(int j=k1; j<=k2; j++) {
            if(i-j >= 0) {
                S1[i] += S0[i-j];
            }
        }
    }
    int res = S0[n] + S1[n];
    cout << res << "\n";
}

int main()
{
    scanf("%d%d%d", &n, &k1, &k2);
    solve();
}

