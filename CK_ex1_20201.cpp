// CAP

#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;

int solve(int a[], int n, int b[], int m)
{
    map<int,int> mp;
    int cnt = 0;
    for(int i=0; i<n; i++) mp[a[i]]++;
    for(int i=0; i<m; i++) {
        if(mp[b[i]] > 0) cnt++;
    }
    return cnt;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n, m;
        int a[MAX], b[MAX];
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        scanf("%d", &m);
        for(int i=0; i<m; i++) scanf("%d", &b[i]);
        cout << solve(a,n,b,m) << "\n";
    }

    return 0;
}

/*
1
4
2 1 4 3
3
1 5 4
*/
