#include <bits/stdc++.h>
using namespace std;

const int Q = 1e9 + 7;
const int MAX = 105;
int n, M;
int a[MAX], x[MAX];
int T=0, cnt=0;

bool check(int i, int k)
{
    if(k < n) return true;
    return T + a[k]*i == M;
}

void Try(int k)
{
    for(int i=1; i<=(M-T-(n-k))/a[k]; i++) {
        if(check(i, k)) {
            x[k] = i;
            T += a[k]*i;
            if(k == n) {
                cnt++;
                cnt = cnt%Q;
            }
            else Try(k+1);
            T -= a[k]*i;
        }
    }
}

int main()
{
    int sum = 0;
    scanf("%d%d", &n, &M);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    M += sum;
    Try(1);
    cout << cnt << "\n";

    return 0;
}

/*
3 4
2 3 2

5 60
1 2 3 4 5
*/
