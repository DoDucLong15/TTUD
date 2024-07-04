#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int N, Q;
vector<pair<int,int>> v;
set<int> st;
map<int,int> mp;
int X[MAX];

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for(int i=1; i<=N; i++) {
        int x, y;
        cin >> x >> y;
        st.insert(y);
        v.push_back(make_pair(x,y));
    }
    for(int i=0; i<Q; i++) {
        cin >> X[i];
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=1; i<N; i++) {
        v[i].first += v[i-1].first;
        mp[v[i].second] = v[i].first;
    }
    mp[v[0].second] = v[0].first;

    for(int i=0; i<Q; i++) {
        auto it = st.lower_bound(X[i]);
        if(it != st.end() && *it == X[i]) cout << mp[*it] << "\n";
        else {
            if(it == st.begin()) cout << 0 << "\n";
            else {
                it--;
                cout << mp[*it] << "\n";
            }
        }
    }

    return 0;
}
