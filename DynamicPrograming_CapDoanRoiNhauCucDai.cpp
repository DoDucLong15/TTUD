#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int n;
vector<pair<int,int>> v;
int L[MAX], R[MAX];
int x_min = INT_MAX, x_max = INT_MIN;

int main()
{
    scanf("%d", &n);
    int a, b;
    for(int i=0; i<n; i++) {
        scanf("%d%d", &a, &b);
        v.push_back(make_pair(a,b));
        x_min = min(x_min, a);
        x_max = max(x_max, b);
    }
    memset(L, INT_MIN, sizeof(L));
    memset(R, INT_MIN, sizeof(R));
    for(int i=0; i<n; i++) {
        int p = v[i].first;
        int q = v[i].second;
        L[q] = max(L[q], q-p);
        R[p] = max(R[p], q-p);
    }
    L[x_min] = 0;
    for(int i=x_min+1; i<=x_max; i++) {
        L[i] = max(L[i-1], L[i]);
    }
    R[x_max] = 0;
    for(int i=x_max-1; i>=x_min; i--) {
        R[i] = max(R[i+1], R[i]);
    }
    int res = INT_MIN;
    for(int i=x_min; i<x_max; i++) {
        res = max(res, L[i] + R[i+1]);
    }
    if(res == INT_MIN) cout << "-1\n";
    else cout << res << "\n";

    return 0;
}
