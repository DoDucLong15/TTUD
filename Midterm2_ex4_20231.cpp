#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n;
int c[MAX][MAX]; //distance
int mem[MAX][1<<MAX];

int Try(int i, int S)
{
    if(S == ((1<<n)-1)) {
        return mem[i][S] = c[i][0];
    }
    if(mem[i][S] != -1) return mem[i][S];
    int res = INT_MAX;
    for(int j=1; j<n; j++) {
        if(S & (1<<j)) continue;
        res = min(res, c[i][j] + Try(j, S|(1<<j)));
    }
    return mem[i][S] = res;
}

void Trace(int i, int S)
{
    cout << i+1 << " ";
    if(S == ((1<<n)-1)) return;
    for(int j=1; j<n; j++) {
        if(S & (1<<j)) continue;
        if(mem[i][S] == c[i][j] + mem[j][S|(1<<j)]) {
            Trace(j, S|(1<<j));
            break;
        }

    }
}

int main()
{
    memset(mem, -1, sizeof(mem));
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) scanf("%d", &c[i][j]);
    Try(0,1);
    cout << n << "\n";
    Trace(0,1);
    cout << "\n";

    return 0;
}

/*
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
*/
