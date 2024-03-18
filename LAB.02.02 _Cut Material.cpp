#include <bits/stdc++.h>
using namespace std;

const int MAX = 11;
int H, W, n, wk, hk;
vector<pair<int,int> > v;
int mark[MAX][MAX];

bool check(int vo, int vx, int vy, int k)
{
    int hk = v[k].first;
    int wk = v[k].second;
    if(vo == 1) {
        wk = v[k].first;
        hk = v[k].second;
    }
    if(vx + wk > W) return false;
    if(vy + hk > H) return false;
    for(int i=vx; i<=vx+wk-1; i++)
        for(int j=vy; j<=vy+hk-1; j++) {
            if(mark[i][j]) return false;
        }
}

void doMark(int vo, int vx, int vy, int k, bool mark_value)
{
    int hk = v[k].first;
    int wk = v[k].second;
    if(vo == 1) {
        wk = v[k].first;
        hk = v[k].second;
    }
    for(int i=vx; i<=vx+wk-1; i++)
        for(int j=vy; j<=vy+hk-1; j++) {
            mark[i][j] = mark_value;
        }
}

void GhiNhan()
{
    cout << "1" << "\n";
    exit(1);
}

void Try(int k)
{
    for(int vo=0; vo <= 1; vo++) {
        int hk = v[k].first;
        int wk = v[k].second;
        if(vo == 1) {
            wk = v[k].first;
            hk = v[k].second;
        }
        for(int vx=0; vx <= W-wk; vx++)
            for(int vy=0; vy <= H-hk; vy++) {
                if(check(vo, vx, vy, k)) {
                    doMark(vo, vx, vy, k, 1);
                    if(k==(n-1)) GhiNhan();
                    else Try(k+1);
                    doMark(vo, vx, vy, k, 0);
                }
            }
    }
}

int main()
{
    scanf("%d%d", &H, &W);
    scanf("%d", &n);
    int p, q;
    for(int i=0; i<n; i++) {
        scanf("%d%d", &p, &q);
        v.push_back({p, q});
    }

    Try(0);
    cout << "0" << "\n";

    return 0;
}
