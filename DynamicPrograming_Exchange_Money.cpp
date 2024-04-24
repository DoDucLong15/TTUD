#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 20;
const int MAX = 1e5 + 5;
int D[N], mam[N][MAX];

int minCoin(int i, int x)
{
    //x coin co the doi it nhat D1, D2, ..., Di
    if(x < 0 || i == 0) return INF;
    if(x == 0) return 0;

    if(mem[i][x] != -1) return mem[i][x];
    int res = INF;
    res = min(res, 1 + mem[i][x-D[i]);
    res = min(res, mem[i-1][x]);
    mem[i][x] = res;
    return res;
}

int Trace(int i, int x)
{
    if(x <= 0 || i == 0) return;

    if(mem[i][x] = 1 + mem[i][x-D[i]) {
        cout << D[i] << ' ';
        Trace(i, x-D[i]);
    }
    else Trace(i-1, x);
}

int main()
{
    memset(mem, -1, sizeof(mem));
}
