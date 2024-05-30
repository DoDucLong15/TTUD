#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, m;
int c[MAX][MAX]; //distance between 2 city
int f = 0, cnt=0;
int road[MAX]; //luu vet duong di
bool mark[MAX]; //danh dau thanh pho da duoc tham chua

bool check(int i, int k)
{
    //thanh pho i, diem thu k
    if(mark[i]) return false;
    return true;
}

void Try(int k)
{
    for(int i=2; i<=n; i++) {
        if(check(i, k)) {
            road[k] = i;
            mark[i] = true;
            f += c[road[k-1]][i];
            if(k == (n-1)) {
                if(f + c[road[n-1]][1] <= m) cnt++;
            }
            else if(f <= m) Try(k+1);
            mark[i] = false;
            f -= c[road[k-1]][i];
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) scanf("%d", &c[i][j]);
    road[0] = 1; mark[1] = true;
    Try(1);
    cout << cnt << "\n";

    return 0;
}

/*
4 10
0 1 2 6
1 0 5 4
2 5 0 3
6 4 3 0
*/
