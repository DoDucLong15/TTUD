#include <bits/stdc++.h>
using namespace std;

int n, a[25];

void GhiNhan()
{
    for(int i=0; i<n; i++) cout << a[i];
    cout << "\n";
}

void Try(int k)
{
    for(int i=0; i<=1; i++) {
        a[k] = i;
        if(k == (n-1)) GhiNhan();
        else Try(k+1);
    }
}

int main()
{
    scanf("%d", &n);
    Try(0);

    return 0;
}
