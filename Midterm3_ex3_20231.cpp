#include <bits/stdc++.h>
using namespace std;

int n;
map<int,int> mp; // danh dau cac so da duoc tham

int solve(int n)
{
    queue<pair<int,int>> q; //{num, so buoc}
    q.push(make_pair(n,0));
    while(!q.empty()) {
        auto d = q.front();
        q.pop();
        if(d.first == 0) {
            return d.second;
        }
        if(d.first - 5 >= 0 && mp[d.first-5] == 0) {
            q.push(make_pair(d.first-5, d.second+1));
            mp[d.first-5] = 1;
        }
        if(d.first + 2 <= 10000 && mp[d.first+2] == 0) {
            q.push(make_pair(d.first+2, d.second+1));
            mp[d.first+2] = 1;
        }
    }
    return INT_MAX;
}

int main()
{
    scanf("%d", &n);

    cout << solve(n) << "\n";

    return 0;
}
