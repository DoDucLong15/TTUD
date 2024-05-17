#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N], mem[N];

int solve(int k)
{
    if(k==1) return mem[1] = a[1];
    if(mem[k] != -1) return mem[k];
    int value = max(solve(k-1) + a[k], a[k]);
    mem[k] = value;
    return value;
}

int main()
{
    memset(mem, -1, sizeof(mem));
    mem[0] = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    solve(n);
    int res = INT_MIN;
    for(int i=1; i<=n; i++) res = max(res, mem[i]);
    cout << res << "\n";

    return 0;
}
