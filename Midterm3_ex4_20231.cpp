#include <bits/stdc++.h>
using namespace std;

const int MAX = 15;
int n; //number of client
int K; //number of truck
int Q; //capacity of a truck
int d[MAX]; // pepsi
int c[MAX][MAX]; //distance between 2 client
int M; //so cap danh sach
int conflict[MAX][MAX] = {0}; //list client khong chung xe
int nBr = 0; //luu so xe duoc su dung
int segment = 0; //so chang da di duoc
int f = 0, f_min = INT_MAX;
int y[MAX]; //diem dau tien cua cac xe
int x[MAX]; //diem ke tiep cua i la x[i]
bool mark[MAX]; //danh dau khach hang da duoc tham chua
int load[MAX]; //luu luong hang cua cac xe
map<int,int> mp; //{khach hang, xe}
int c_min = INT_MAX;

void GhiNhan()
{
    f_min = min(f_min, f);
}

bool checkX(int i, int k)
{
    //khach hang thu i, xe tai thu k
    if(i>0 && mark[i]) return false;
    if(load[k] + d[i] > Q) return false;
    if(i > 0) {
        for(int j=1; j<=n; j++) {
            if(conflict[i][j] == 1 && mark[j] && mp[j] == k) return false;
        }
    }
    return true;
}

bool checkY(int i, int k)
{
    //khach hang thu i, xe tai thu k
    if(i == 0) return true;
    if(mark[i]) return false;
    if(load[k] + d[i] > Q) return false;
    return true;
}

void TryX(int s, int k)
{
    if(s == 0) {
        if(k < K) {
            TryX(y[k+1], k+1);
        }
        return;
    }
    for(int i=0; i<=n; i++) {
        if(checkX(i,k)) {
            x[s] = i;
            f += c[s][i];
            segment++;
            mark[i] = true;
            load[k] += d[i];
            mp[i] = k;
            if(i == 0) {
                if(k < K) {
                    if(f + (n+nBr-segment)*c_min < f_min) TryX(y[k+1], k+1);
                }
                else if(n+nBr == segment) GhiNhan();
            }
            else if(f + (n+nBr-segment)*c_min < f_min) TryX(i, k);
            f -= c[s][i];
            segment--;
            mark[i] = false;
            load[k] -= d[i];
            mp[i] = 0;
        }
    }
}

void TryY(int k)
{
    //gia su y[k+1] >= y[k]
    int s = 0;
    if(y[k-1] > 0) s = y[k-1] + 1;
    for(int i=s; i<=n; i++) {
        if(checkY(i,k)) {
            y[k] = i;
            mark[i] = true;
            load[k] += d[i];
            f += c[0][i];
            mp[i] = k;
            if(i > 0) {
                segment++;
            }
            if(k==K) {
                nBr = segment;
                TryX(y[1], 1);
            }
            else TryY(k+1);
            mark[i] = false;
            load[k] -= d[i];
            f -= c[0][i];
            if(i > 0) {
                segment--;
            }
            mp[i] = 0;
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &K, &Q);
    for(int i=1; i<=n; i++) {
        scanf("%d", &d[i]);
        mark[i] = false;
    }
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++) {
            scanf("%d", &c[i][j]);
            if(i != j) c_min = min(c_min, c[i][j]);
        }
    scanf("%d", &M);
    int a, b;
    for(int i=0; i<M; i++) {
        scanf("%d%d", &a, &b);
        conflict[a][b] = 1;
        conflict[b][a] = 1;
    }
    y[0] = 0; //linh canh
    TryY(1);
    if(f_min == INT_MAX) cout << "-1\n";
    else cout << f_min << "\n";

    return 0;
}

/*
3 2 7
3 2 3
0 2 3 1
4 0 1 3
2 3 0 4
3 2 4 0
1
1 2

Truck 1: 0 -> 3 -> 1 -> 0
Truck 2: 0 -> 2 -> 0
Output: 12
*/
