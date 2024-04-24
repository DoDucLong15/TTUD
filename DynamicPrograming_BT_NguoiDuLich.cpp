#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
const int INF = 1e9;
int n;
int c[MAX][MAX], mem[MAX][1<<MAX];

int TSP(int i, int S)
{
    if(S == (1 << MAX) - 1) return mem[i][S] = c[i][0];
    if(mem[i][S] != -1) return mem[i][S];

    int res = INF;
    for(int j=1; j<=n; j++) {
        if(S & (1 << j)) continue;
        res = min(res, c[i][j] + TSP(j, S | (1 << j)));
    }
    return mem[i][S] = res;
}

void Trace_recursive(int i, int S)
{
    cout << i << " -> ";
    if(S == (1 << MAX) - 1) cout << 0 << endl;
    for(int j=1; j<=n; j++) {
        if(S & (1 << j)) continue;
        if(mem[i][S] == c[i][j] + mem[j][S | (1 << j)]) {
            Trace(j, S| (1 << j));
            break;
        }
    }
}

int main()
{
    memset(mem, -1, sizeof(mem));
    Trace(0, 1 << 0);
}
