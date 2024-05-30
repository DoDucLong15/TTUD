#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int t, n, c;
int a[MAX];

int check(int mid)
{
    int pos = a[0], cnt = 1;
    for(int i=1; i<n; i++) {
        if(a[i] - pos >= mid) {
            cnt++;
            pos = a[i];
            if(cnt == c) return true;
        }
    }
    return false;
}

int solve()
{
    sort(a, a+n);
    int left = 1, right = a[n-1]-a[0];
    int res = INT_MIN;
    while(left < right) {
        int mid = (left + right)/2;
        if(check(mid)) {
            res = max(res, mid);
            left = mid+1;
        }
        else right = mid;
    }
    return res;
}

int main()
{
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%d%d", &n, &c);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        cout << solve() << "\n";
    }

    return 0;
}
