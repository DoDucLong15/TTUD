#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n, L1, L2, a[MAX];
int mem[MAX];

//int solve()
//{
//    int res = INT_MIN;
//    for(int i=1; i<=L1; i++) mem[i] = a[i];
//    for(int i=L1+1; i<=n; i++) {
//        int j = (i-L2) > 0 ? i-L2 : 1;
//        for(; j<=(i-L1); j++) {
//            mem[i] = max(mem[i], mem[j] + a[i]);
//        }
//        res = max(res, mem[i]);
//    }
//    return res;
//}

int solve()
{
    for(int i=1; i<=L1; i++) {
        mem[i] = a[i];
    }
    priority_queue<int> q;
    q.push(a[1]);
    for(int i=L1+1; i<=n; i++) {
        int t = q.top();
        mem[i] = t + a[i]; //cap nhat ket qua
        q.push(mem[i-L1+1]); //cap nhat de i luon cach q.top() >= L1
    }
    int result = 0;
    for(int i=n-L2; i<=n; i++) {
        result = max(result, mem[i]);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d%d%d", &n, &L1, &L2);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    cout << solve() << "\n";

    return 0;
}
