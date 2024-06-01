//Subset ò a sequence sum í from A to B

#include <bits/stdc++.h>
using namespace std;

const int MAX = 25;
int n, A, B;
int a[MAX], sum[MAX]; //sum[i] tong tu phan tu 1->i
int cnt = 0;

int main()
{
    scanf("%d%d%d", &n, &A, &B);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    //tinh tong
    sum[0] = 0;
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];

    for(int i=1; i<=n; i++)
        for(int j=0; j<i; j++) {
            if((sum[i]-sum[j]) >=A && (sum[i]-sum[j]) <= B) cnt++;
        }
    cout << cnt << "\n";

    return 0;
}

/*
5 5 10
9 4 10 3 7
*/

