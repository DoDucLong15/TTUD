#include <bits/stdc++.h>
using namespace std;

const int MAX = 25;
int n;
int a[MAX];
int load[2];
int res = INT_MAX;

void GhiNhan()
{
    res = min(res, abs(load[1]-load[0]));
}

void Try(int k)
{
    for(int i=0; i<=1; i++) {
        load[i] += a[k];
        if(k == (n-1)) GhiNhan();
        else Try(k+1);
        load[i] -= a[k];
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    Try(0);

    cout << res << "\n";

    return 0;
}

/*
5
208 750 114 184 538
*/
