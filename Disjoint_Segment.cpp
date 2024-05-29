#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int main()
{
    scanf("%d", &n);
    int a, b;
    for(int i=0; i<n; i++) {
        scanf("%d%d", &a, &b);
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0, last = -1;
    for(int i=0; i<v.size(); i++) {
        if(v[i].first > last) {
            cnt++;
            last = v[i].second;
        }
        else continue;
    }
    cout << cnt << "\n";

    return 0;
}
