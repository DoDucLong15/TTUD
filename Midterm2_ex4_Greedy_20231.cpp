#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int n;
int c[MAX][MAX]; //distance
bool mark[MAX];
int road[MAX]; //luu vet

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) scanf("%d", &c[i][j]);

    road[0] = 1;
    mark[1] = true;
    for(int i=1; i<=n-1; i++) {
        //tim diem den tiesp theo (min)
        int lastPoint = road[i-1];
        int minPosition = 0;
        c[lastPoint][0] = INT_MAX;
        for(int j=1; j<=n; j++) {
            if(j != lastPoint && !mark[j]) {
                if(c[lastPoint][j] <= c[lastPoint][minPosition]) {
                    minPosition = j;
                }
            }
            else continue;
        }
        road[i] = minPosition;
        mark[minPosition] = true;
    }
    cout << n << "\n";
    for(int i=0; i<n; i++) cout << road[i] << " ";
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

