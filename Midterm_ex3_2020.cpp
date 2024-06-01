//DIGITS

#include <bits/stdc++.h>
using namespace std;

int t, n;
bool mark[10]; //danh dau cac so 0->9 da duoc chon
int a[10], cnt;

void init()
{
    for(int i=0; i<=9; i++) mark[i] = false;
    cnt = 0;
}

bool check(int i, int k)
{
    if(mark[i]) return false;
    if(k == 1 || k==3) {
        if(i == 0) return false;
    }
    return true;
}

void GhiNhan()
{
    int p = a[1]*1000 + a[2]*100 + a[3]*10 + a[4];
    int q =  a[3]*10000 + a[5]*1000 + a[6]*100 + a[7]*10 + a[4];
    if(p + q == n) cnt++;
}

void Try(int k) //k 1->7
{
    for(int i=0; i<=9; i++) {
        if(check(i,k)) {
            a[k] = i;
            mark[i] = true;
            if(k == 7) GhiNhan();
            else Try(k+1);
            mark[i] = false;
        }
    }
}

int main()
{
    // H U S T O I C
    // a[1] -> a[7]
    //HUST = a[1]*1000 + a[2]*100 + a[3]*10 + a[4];
    //SOICT = a[3]*10000 + a[5]*1000 + a[6]*100 + a[7]*10 + a[4]
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        init();
        Try(1);
        cout << cnt << "\n";
    }

    return 0;
}

/*
5
17868
29119
49862
78952
1000002
*/
