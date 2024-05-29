#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, m, T=0;
int X[MAX], cnt=0;

bool check(int i, int k)
{
    if(k < n) return true;
    else return (T + i) == m; //phan tu cuoi cung
}

void GhiNhan()
{
    for(int i=1; i<=n; i++) cout << X[i] << " ";
    cout << "\n";
    cnt++;
}

void Try(int k)
{
    for(int i=1; i<=(m-T-(n-k)); i++) {
        if(check(i,k)) {
            X[k] = i;
            T += i;
            if(k == n) GhiNhan();
            else Try(k+1);
            T -= i;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    Try(1);
    cout << cnt << "\n";

    return 0;
}
