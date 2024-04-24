#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
int L[MAX], R[MAX];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<=n+1; i++) {
        L[i] = INT_MIN;
        R[i] = INT_MIN;
    }

    int a, b;
    for(int i=0; i<n; i++) {
        scanf("%d%d", &a, &b);
        L[b] = max(L[b], b-a);
        R[a] = max(R[a], b-a);
    }
    for(int i=1; i<=n; i++) L[i] = max(L[i], L[i-1]);
    for(int i=n; i>=1; i--) R[i] = max(R[i], R[i+1]);
    int res = INT_MIN;
    for(int i=0; i<=n; i++) res = max(res, L[i] + R[i+1]);
    if(res == INT_MIN) cout << "-1\n";
    else cout << res << "\n";

    return 0;
}
