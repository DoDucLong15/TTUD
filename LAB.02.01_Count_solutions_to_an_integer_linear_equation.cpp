/*

*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
int n, M, a[MAX], sum=0, dem=0;

void GhiNhan()
{
    if(sum == M) dem++;
}

void Try(int k)
{
    for(int i=1; i<(M/a[k-1]); i++) {
        sum += a[k-1] * i;
        if(sum > M || k==n) GhiNhan();
        else Try(k+1);
        sum -= a[k-1] * i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d%d", &n, &M);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    Try(1);
    cout << dem << "\n";

    return 0;
}
