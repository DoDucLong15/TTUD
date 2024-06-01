//Backtracking

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int N; //so san pham
int M; //so ke
int Q[MAX][MAX]; //Q[i][j] so luong san pham i trong ke j
int q[MAX]; //so luong san pham i anh ta phai lay la q[i]
int d[MAX][MAX]; //khoang cach giua 2 ke
vector<int> result;
int trace[MAX];
int f=0, f_min = INT_MAX;
bool mark[MAX];

bool checkResult()
{
    for(int i=1; i<=N; i++)
        if(q[i] > 0) return false;
    return true;
}

void GhiNhan(int k)
{
    if(f + d[trace[k]][0] < f_min) {
        f_min = f + d[trace[k]][0];
        result.clear();
        for(int i=1; i<=k; i++) result.push_back(trace[i]);
    }
}

void Try(int k)
{
    //k la cac buoc
    for(int i=1; i<=M; i++) {
        if(!mark[i]) {
            f += d[trace[k-1]][i];
            trace[k] = i;
            mark[i] = true;
            for(int j=1; j<=N; j++) {
                q[j] -= Q[j][i];
            }
            if(checkResult()) {
                GhiNhan(k);
            }
            else if(k < M) {
                 if(f < f_min) Try(k+1);
            }
            mark[i] = false;
            for(int j=1; j<=N; j++) {
                q[j] += Q[j][i];
            }
            f -= d[trace[k-1]][i];
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) {
            scanf("%d", &Q[i][j]);
        }
    for(int i=0; i<=M; i++)
    for(int j=0; j<=M; j++) {
        scanf("%d", &d[i][j]);
    }
    for(int i=1; i<=N; i++) scanf("%d", &q[i]);
    trace[0] = 0;
    Try(1);
    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
    cout << "\n";
    return 0;
}

/*
6 5
3 2 2 4 2
4 3 7 3 5
6 7 2 5 4
2 3 3 2 1
2 5 7 6 1
7 2 1 6 5
0 16 10 13 13 19
16 0 8 3 19 5
10 8 0 7 23 11
13 3 7 0 16 6
13 19 23 16 0 22
19 5 11 6 22 0
8 7 4 8 11 13

Output:
4
2 3 1 5
*/

//M = 1000, truong hop toi nhat phai duyet het
//=> tham lam, tai moi buoc chon diem gan nhat, cho den khi lay het dc hang
