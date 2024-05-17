#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, M;
int a[N];

int solve(int n, int M)
{
    if(M==0) return 1;
    if(n < 0) return 0;
    if(M < 0) return 0;
    int res = solve(n, M-a[n]) + solve(n-1,M);
    return res;
}

int main()
{
    int sum = 0;
    scanf("%d%d", &n, &M);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    cout << solve(n-1,M-sum) << "\n";

    return 0;
}
