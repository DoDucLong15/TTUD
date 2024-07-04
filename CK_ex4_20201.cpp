//ROUTE

#include <bits/stdc++.h>
using namespace std;

const int MAX = 55;
int n, Q;
int a[MAX];
int d[MAX][MAX];
int f = 0;
bool mark[MAX];
int trace[MAX];

int main()
{
    scanf("%d%d", &n, &Q);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++) scanf("%d", &d[i][j]);
    trace[0] = 0;
    int k = 1;
    while(Q > 0 && k <= n) {
        int minVal = INT_MAX, minPos = -1;
        for(int i=1; i<=n; i++) {
            if(!mark[i] && d[trace[k-1]][i] < minVal) {
                minVal = d[trace[k-1]][i];
                minPos = i;
            }
        }
        mark[minPos] = true;
        f += d[trace[k-1]][minPos];
        trace[k] = minPos;
        k++;
        Q -= a[minPos];
    }
    if(Q > 0) cout << "-1\n";
    else {
        cout << f + d[trace[k-1]][0] << "\n";
        cout << k-1 << "\n";
        for(int i=1; i<k; i++) cout << trace[i] << " ";
        cout << "\n";
    }

    return 0;
}

/*
5 10
3 6 2 4 1
0 3 6 4 6 2
3 0 7 8 2 1
6 7 0 1 4 9
4 8 1 0 3 4
6 2 4 3 0 1
2 1 9 4 1 0
*/
