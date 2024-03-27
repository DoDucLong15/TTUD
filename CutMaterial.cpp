#include <bits/stdc++.h>
using namespace std;

const int MAX = 15;
int H, W, n;
vector<pair<int,int> > v;
bool mark[MAX][MAX];

bool check(int vo, int vx, int vy, int k)
{
    int hk = v[k].first;
    int wk = v[k].second;
    if(vo == 1) {
        hk = v[k].second;
        wk = v[k].first;
    }
    if(vx + wk > W) return false;
    if(vy + hk > H) return false;
    for(int i=vx; i<=vx+wk-1; i++)
        for(int j=vy; j<=vy+hk-1; j++) {
            if(mark[i][j]) return false;
        }
    return true;
}

void doMark(int vo, int vx, int vy, int k, bool value)
{
    int hk = v[k].first;
    int wk = v[k].second;
    if(vo == 1) {
        hk = v[k].second;
        wk = v[k].first;
    }
    for(int i=vx; i<=vx+wk-1; i++)
        for(int j=vy; j<=vy+hk-1; j++) {
            mark[i][j] = value;
        }
}

void GhiNhan()
{
    cout << "1\n";
    exit(1);
}

void Try(int k)
{
    for(int vo=0; vo<=1; vo++) {
        int hk = v[k].first;
        int wk = v[k].second;
        if(vo == 1) {
            hk = v[k].second;
            wk = v[k].first;
        }
        for(int vx=0; vx<=W-wk; vx++)
            for(int vy=0; vy<=H-hk; vy++) {
                if(check(vo, vx, vy, k)) {
                    doMark(vo, vx, vy, k, true);
                    if(k == (n-1)) GhiNhan();
                    else Try(k+1);
                    doMark(vo, vx, vy, k, false);
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
    cout << "0\n";

    return 0;
}
