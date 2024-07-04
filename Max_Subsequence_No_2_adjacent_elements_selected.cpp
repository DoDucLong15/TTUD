#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
int a[MAX];
int mem[MAX];

int solve()
{
    memset(mem, 0, sizeof(mem));
    mem[1] = a[1];
    priority_queue<int> q;
    int k = 1;
    for(int i=2; i<=n; i++) {
        mem[i] = a[i];
        if(!q.empty()) {
            mem[i] = q.top() + a[i];
        }
        q.push(mem[k]);
        k++;
    }
    while(k <= n) {
        q.push(mem[k]);
        k++;
    }
    return q.top();
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    cout << solve() << "\n";

    return 0;
}
