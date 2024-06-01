// Max subsequence no 2 adjacent elements selected

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
int a[MAX];
priority_queue<int> q;
int mem[MAX];
int res = INT_MIN;

int main()
{
    memset(mem, 0, sizeof(mem));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    if(n == 1) res = a[1];
    else {
        mem[1] = a[1];
        mem[2] = a[2];
        res = max(a[1], a[2]);
        q.push(mem[1]);
        int k = 2;
        for(int i=3; i<=n; i++) {
            mem[i] = q.top() + a[i];
            q.push(mem[k]);
            k++;
            res = max(res, mem[i]);
        }
    }
    cout << res << "\n";

    return 0;
}

/*
5
2 5 4 6 7
*/
