#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > v;

bool compare(pair<int,int> one, pair<int,int> two)
{
    return one.second < two.second;
}

void solve()
{
    int result = 0;
    int last = INT_MIN;
    for(int i=0; i<n; i++) {
        pair<int,int> temp = v[i];
        if(temp.first > last) {
            result++;
            last = temp.second;
        }
    }
    cout << result << "\n";
}

int main()
{
    int a, b;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &a, &b);
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);
    solve();

    return 0;
}
