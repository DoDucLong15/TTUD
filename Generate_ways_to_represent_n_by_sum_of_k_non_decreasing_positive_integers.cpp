#include <bits/stdc++.h>
using namespace std;

const int N = 45;
int k, n;
int a[N], sum=0;

bool check(int i, int v)
{
    if(v==0) return true;
    else {
        if(i < a[v-1]) return false;
    }
    return true;
}

void GhiNhan()
{
    int d = n - sum;
    if(d < a[k-2]) return;
    for(int i=0; i<k-1; i++) cout << a[i] << " ";
    cout << d << "\n";
}

void Try(int v)
{
    for(int i=1; i<=n-1; i++) {
        if(check(i, v)) {
            a[v] = i;
            sum+=i;
            if(v == (k-2)) GhiNhan();
            else if(i <= (n-sum)/(k-v-1)) Try(v+1);
            sum-=i;
        }
    }
}

int main()
{
    scanf("%d%d", &k, &n);
    Try(0);

    return 0;
}
