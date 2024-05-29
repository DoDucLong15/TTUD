#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;

bool check_array_equality(int a[], int n, int b[], int m)
{
    if(n != m) return false;
    for(int i=0; i<n; i++)
        if(a[i] != b[i]) return false;
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n,m;
        int a[MAX], b[MAX];
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<m; i++) scanf("%d", &b[i]);
        if(check_array_equality(a,n,b,m)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
