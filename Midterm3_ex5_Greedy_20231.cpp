#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int N; //so san pham
int M; //so ke
int Q[MAX][MAX]; //Q[i][j] so luong san pham i trong ke j
int q[MAX]; //so luong san pham i anh ta phai lay la q[i]
int d[MAX][MAX]; //khoang cach giua 2 ke
int trace[MAX]; //luu cac ke da tham
int f=0; //luu tong quang duong
bool mark[MAX];

bool checkResult()
{
    for(int i=1; i<=N; i++)
        if(q[i] > 0) return false;
    return true;
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
    int k = 1;
    while(!checkResult()) {
        int e = trace[k-1];
        int minPos = 0, minVal = INT_MAX;
        //tim diem tiep theo cach 1 doan ngan nhat
        for(int j=1; j<=M; j++) {
            if(!mark[j] &&  d[e][j] < minVal) {
                minPos = j;
                minVal = d[e][j];
            }
        }
        trace[k] = minPos;
        mark[minPos] = true;
        for(int j=1; j<=N; j++) {
            q[j] -= Q[j][minPos];
        }
        k++;
    }
    cout << k-1 << "\n";
    for(int i=1; i<k; i++) cout << trace[i] << " ";
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

