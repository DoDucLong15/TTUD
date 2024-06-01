//SEQMX

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, k;
int a[MAX];
int sum[MAX]; //tong tu 1->i

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    double res = 0.0;
    //tinh tong truoc
    sum[0] = 0;
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i-1];
    //
    for(int i=k; i<=n; i++) {
        for(int j=0; j<=i-k; j++) {
            double value = (double)(sum[i] - sum[j])/(double)(i-j);
            res = max(res, value);
        }
    }
    cout << res << "\n";

    return 0;
}

/*
7 3
2 4 5 1 3 4 1
*/
