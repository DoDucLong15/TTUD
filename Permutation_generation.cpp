#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, a[MAX];

bool check(int i, int k)
{
    for(int j=1; j<k; j++)
        if(a[j] == i) return false;
    return true;
}

void GhiNhan()
{
    for(int i=1; i<=n; i++) cout << a[i] << " ";
    cout << "\n";
}

void Try(int k)
{
    for(int i=1; i<=n; i++) {
        if(check(i,k)) {
            a[k] = i;
            if(k==n) GhiNhan();
            else Try(k+1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);

    return 0;
}
