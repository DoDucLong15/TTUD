#include <bits/stdc++.h>
using namespace std;

int H, W, n;
int h[15], w[15];
bool mark[15][15];

bool check(int i, int j, int height, int width)
{
    if(i + height > H) return false;
    if(j + width > W) return false;
    for(int u=i; u<=i+height-1; u++)
        for(int v=j; v<=j+width-1; v++) {
            if(mark[u][v]) return false;
        }
    return true;
}

void doMark(int i, int j, int height, int width, bool value)
{
    for(int u=i; u<=i+height-1; u++)
        for(int v=j; v<=j+width-1; v++) {
            mark[u][v] = value;
        }
}

void GhiNhan()
{
    cout << "1\n";
    exit(1);
}

void Try(int k)
{
    //manh ghep thu k
    for(int vo=0; vo<=1; vo++) {
        //vo=1 la xoay 90 do
        int height=h[k], width=w[k];
        if(vo==1) {
            height = w[k];
            width = h[k];
        }
        for(int i=0; i<=H-height; i++)
            for(int j=0; j<=W-width; j++) {
                if(check(i,j,height,width)) {
                    doMark(i, j, height, width, true);
                    if(k == (n-1)) GhiNhan();
                    else Try(k+1);
                    doMark(i, j, height, width, false);
                }
            }
    }
}

int main()
{
    scanf("%d%d%d", &H, &W, &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &h[i], &w[i]);
    }
    Try(0);
    cout << "0\n";

    return 0;
}
