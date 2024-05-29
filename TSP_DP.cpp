#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n; // number of city
int c[MAX][MAX]; //distance between two city
int mem[MAX][1<<MAX];

int TSP(int i, int S)
{
    if(S == (1<<n)-1) {
        return mem[i][S] = c[i][0];
    }
    if(mem[i][S] != -1) return mem[i][S];
    int res = INT_MAX;
    for(int j=1; j<n; j++) {
        if(S & (1<<j)) continue;
        res = min(res, c[i][j] + TSP(j, S | (1<<j)));
    }
    return mem[i][S] = res;
}

void Trace(int i, int S)
{
    cout << i+1 << "->";
    if(S == (1<<n)-1) cout << 1 << "\n";
    for(int j=1; j<n; j++) {
        if(S & (1<<j)) continue;
        if(mem[i][S] == c[i][j] + mem[j][S | (1<<j)]) {
            Trace(j, S|(1<<j));
            break;
        }
    }
}
int main()
{
    memset(mem, -1, sizeof(mem));
    //do di tu thanh pho 1, qua (n-1) thanh pho roi quay lai 1
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            scanf("%d", &c[i][j]);
        }
    cout << TSP(0,1) << "\n";
    Trace(0,1);
    cout << "\n";

    return 0;
}
