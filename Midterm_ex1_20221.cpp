//k - subsequence weight equa to m

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, k, m;
int a[MAX], sum[MAX]; //sum[i] tong tu phan tu 1->i

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    //tinh tong
    sum[0] = 0;
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];

    int cnt = 0;
    for(int i=k; i<=n; i++) {
        if(sum[i]-sum[i-k] == m) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}

/*
6 3 9
3 2 4 3 2 1
*/
