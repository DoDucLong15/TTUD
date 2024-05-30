// BACP

#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n; //so khoa hoc
int m; //so tiet hoc
int a[MAX][MAX]; //dieu kien tien quyet cac mon hoc
int c[MAX];
int period[MAX]; //khoa hoc i se duoc phan cong cho tiet hoc period[i]
int load[MAX]; //so khoa hoc cua 1 tiet
int result = INT_MAX, res = 0;

bool check(int k, int i)
{
    if(period[k] > 0) return false;
    for(int j=1; j<k; j++) {
        if(a[k][j] == 1 && i >= period[j]) return false;
    }
    return true;
}

void GhiNhan()
{
    result = min(result, res);
}

void Try(int k)
{
    //k la khoa hoc
    for(int i=1; i<=m; i++) {
        if(check(k,i)) {
            period[k] = i;
            load[i] += c[k];
            int temp = res;
            res = max(res, load[i]);
            if(k == n) GhiNhan();
            else if(res < result) Try(k+1);
            period[k] = 0;
            load[i] -= c[k];
            res = temp;
        }
    }
}

int main()
{
    memset(period, 0, sizeof(period));
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) scanf("%d", &a[i][j]);
    Try(1);

    cout << result << "\n";

    return 0;
}
