// LIS1

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int t, n;
int a[MAX];
int mem[MAX];

void init()
{
    memset(mem, 0, sizeof(mem));
}

int solve()
{
    int res = 1;
    mem[0] = 1;
    for(int i=1; i<n; i++) {
        mem[i] = 1;
        for(int j=0; j<i; j++) {
            if(a[i]-a[j]==1) {
                mem[i] = max(mem[i], mem[j]+1);
            }
        }
        res = max(res, mem[i]);
    }
    return res;
}

int main()
{
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        cout << solve() << "\n";
    }

    return 0;
}

/*
1
6
3 1 2 4 3 5
*/
