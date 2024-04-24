#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int n, k;
int a[MAX];

bool check(int i, int v)
{
    if(i <= a[v-1]) return false;
    for(int j=0; j<v; j++)
        if(a[j] == i) return false;
    return true;
}

void GhiNhan()
{
    for(int i=0; i<k; i++) printf("%d ", a[i]);
    printf("\n");
}

void Try(int v)
{
    for(int i=1; i<=n; i++) {
        if(check(i, v)) {
            a[v] = i;
            if(v == k-1) GhiNhan();
            else Try(v+1);
        }
    }
}

int main()
{
    cin >> k>> n;
    Try(0);

    return 0;
}
