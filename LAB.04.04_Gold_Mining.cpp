#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n, L1, L2, a[MAX];
int mem[MAX];

int solve()
{
    int res = INT_MIN;
    for(int i=1; i<=L1; i++) mem[i] = a[i];
    for(int i=L1+1; i<=n; i++) {
        int j = (i-L2) > 0 ? i-L2 : 1;
        for(; j<=(i-L1); j++) {
            mem[i] = max(mem[i], mem[j] + a[i]);
        }
        res = max(res, mem[i]);
    }
    return res;
}

int main()
{
    scanf("%d%d%d", &n, &L1, &L2);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    cout << solve() << "\n";

    return 0;
}
