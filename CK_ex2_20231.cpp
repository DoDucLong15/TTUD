#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 1e3 + 5;
const int Q = 1e9 + 7;
int n;
vector<pair<pair<int,int>,int>> v;
ll mem[MAX];

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
    if(a.first.first == b.first.first) return a.first.second < b.first.second;
    else return a.first.first < b.first.first;
}

ll solve()
{
    ll res = INT_MIN;
    mem[0] = v[0].second;
    for(int i=1; i<n; i++) {
        mem[i] = v[i].second;
        for(int j=0; j<i; j++) {
            if(v[j].first.first <= v[i].first.first && v[j].first.second <= v[i].first.second) {
                mem[i] = max(mem[i], mem[j] + v[i].second);
            }
        }
        res = max(res, mem[i])%Q;
    }
    return res%Q;
}

int main()
{
    memset(mem, -1, sizeof(mem));
    scanf("%d", &n);
    int x,y,c;
    for(int i=0; i<n; i++) {
        scanf("%d%d%d", &x, &y, &c);
        v.push_back(make_pair(make_pair(x,y),c));
    }
    sort(v.begin(), v.end(), cmp);

    cout << solve() << "\n";

    return 0;
}

/*
10
2 4 7
4 2 10
4 6 2
5 5 7
1 3 9
1 5 1
1 1 3
3 1 5
3 3 6
2 2 2
*/
