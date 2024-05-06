#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int n;
vector<pair<pair<int,int>,int> > v;
long long mem[MAX];

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    else
        return a.first.first < b.first.first;
}

void input()
{
    scanf("%d", &n);
    int x,y,c;
    for(int i=1; i<=n; i++) {
        scanf("%d%d%d", &x, &y, &c);
        pair<int,int> temp = make_pair(x,y);
        v.push_back(make_pair(temp,c));
    }
}

void solve()
{
    mem[0] = v[0].second;
    long long res = mem[0];
    for(int i=1; i<n; i++) {
        mem[i] = v[i].second;
        for(int j=0; j<i; j++) {
            if(v[j].first.first <= v[i].first.first && v[j].first.second <= v[i].first.second) {
                mem[i] = max(mem[j]+v[i].second, mem[i]);
            }
        }
        res = max(res, mem[i]);
    }
    cout << res << "\n";
}

int main()
{
    input();
    sort(v.begin(), v.end(), cmp);
    solve();

    return 0;
}
