#include <bits/stdc++.h>
using namespace std;

int a[9][9];
int cnt = 0;

bool check(int x, int i, int j)
{
    if(a[i][j] != 0) return false;
    //Numbers of each row are distinct
    for(int k=0; k<9; k++) {
        if(a[i][k] != 0 && a[i][k] == x) return false;
    }
    //Numbers of each column are distinct
    for(int k=0; k<9; k++) {
        if(a[k][j] != 0 && a[k][j] == x) return false;
    }
    //Numbers on each sub-square 3 x 3 are distinct
    int u = i/3;
    int v = j/3;
    for(int m=3*u; m<=3*(u+1)-1; m++) {
        for(int n=3*v; n<=3*(v+1)-1; n++) {
            if(a[m][n] != 0 && a[m][n] == x) return false;
        }
    }
    return true;
}

void GhiNhan()
{
    cnt++;
}

void Try(int i, int j)
{
    if(a[i][j] != 0) {
        if(i==8 && j==8) GhiNhan();
        else if(j==8) Try(i+1,0);
        else Try(i,j+1);
    }
    for(int x=1; x<=9; x++) {
        if(check(x,i,j)) {
            a[i][j] = x;
            if(i==8 && j==8) GhiNhan();
            else if(j==8) Try(i+1,0);
            else Try(i,j+1);
            a[i][j] = 0;
        }
    }
}

int main()
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            scanf("%d", &a[i][j]);
        }
    Try(0,0);
    cout << cnt << "\n";
}
