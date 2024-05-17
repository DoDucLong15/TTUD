#include <bits/stdc++.h>
using namespace std;

int N, M;
int c[20];
int a[20][20];
int load[20]; //load of period
int f_min = INT_MAX;//luu ket qua
map<int,int> subject;

bool check(int k, int i) //mon hoc k, tiet hoc thu i
{
    if(subject[k] != 0) return false;
    for(int j=1; j<=N; j++) {
        if(a[k][j] == 1 && i <= subject[j]) return false;
    }
    return true;
}

void GhiNhan()
{
    int value = *max_element(load+1, load+N+1);
    f_min = min(f_min, value);
}

void Try(int k) //k la ten khoa hoc
{
    for(int i=1; i<=M; i++) {
        //danh sach tiet hoc
        if(check(k,i)) {
            subject[k] = i;
            load[i] += c[k];
            if(k == N) GhiNhan();
            else Try(k+1);
            subject[k] = 0;
            load[i] -= c[k];
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) {
        scanf("%d", &c[i]);
        subject[i] = 0;
    }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) scanf("%d", &a[i][j]);
    Try(1);
    cout << f_min << "\n";

    return 0;
}
