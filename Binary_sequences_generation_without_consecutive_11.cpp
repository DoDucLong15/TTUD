#include <bits/stdc++.h>
using namespace std;

int n, a[21];

bool check()
{
    for(int i=0; i<n-1; i++)
        if(a[i]==1 && a[i+1]==1) return false;
    return true;
}

void GhiNhan()
{
    if(!check()) return;
    for(int i=0; i<n; i++) printf("%d", a[i]);
    printf("\n");
}

void Try(int k)
{
    for(int i=0; i<=1; i++) {
        a[k] = i;
        if(k ==(n-1)) GhiNhan();
        else Try(k+1);
    }
}

int main()
{
    scanf("%d", &n);
    Try(0);

    return 0;
}
