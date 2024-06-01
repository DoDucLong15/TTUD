// RUN
/*

*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
int a[MAX];

void solve()
{
    int cnt = 1;
    int pos = a[0];
    for(int i=1; i<n; i++) {
        if(a[i] > pos) {
            pos = a[i];
        }
        else {
            cnt++;
            pos = a[i];
        }
    }
    cout << cnt << "\n";
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    solve();

    return 0;
}

/*
6
3 6 1 7 8 2
*/
