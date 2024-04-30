#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int T, N, C;

bool check(int mid, int a[], int N, int C)
{
    int pos = a[0];
    int element = 1;
    for(int i=1; i<N; i++) {
        if(a[i] - pos >= mid) {
            element++;
            pos = a[i];
            if(element == C) return true;
        }
    }
    return false;
}

int solve(int a[], int N, int C)
{
    sort(a, a+N);
    int l = 1, r = a[N-1] - a[0];
    int res = -1;
    while(l < r) {
        int mid = (l+r)/2;
        if(check(mid, a, N, C)) {
            res = max(res, mid);
            l = mid+1;
        }
        else r = mid;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        scanf("%d%d", &N, &C);
        int a[N];
        for(int i=0; i<N; i++) {
            scanf("%d", &a[i]);
        }
        cout << solve(a,N,C) << "\n";
    }
}
