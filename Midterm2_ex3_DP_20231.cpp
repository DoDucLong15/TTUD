#include <bits/stdc++.h>
using namespace std;

const int Q = 1e9 + 7;
const int MAX = 105;
int n, M;
int a[MAX];

int solve(int n, int M)
{
    if(M == 0) return 1;
    if(M < 0) return 0;
    if(n < 0) return 0;
    //n la so luong so
    return (solve(n, M-a[n])%Q + solve(n-1,M)%Q)%Q;
}

int main()
{
    scanf("%d%d", &n, &M);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    cout << solve(n-1,M)%Q << "\n";
    return 0;
}

/*
3 4
2 3 2

5 60
1 2 3 4 5
*/

