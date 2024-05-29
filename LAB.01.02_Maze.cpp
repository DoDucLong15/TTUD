//C++
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int n, m, r, c;
int a[MAX][MAX];
vector<pair<int,int>> option; //{x,y}
bool mark[MAX][MAX]; //danh dau cac o da tham
bool ok = false;
int res = INT_MAX;

void solve(pair<int,int> point) {
    if(a[point.first][point.second] == 1) {
        cout << "-1\n";
        return;
    }
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(point.first, point.second), 1));
    mark[point.first][point.second] = true;
    while(!q.empty()) {
        auto d = q.front();
        q.pop();
        if(d.first.first == 0 || d.first.first == n-1 || d.first.second == 0 || d.first.second == m-1) {
            cout << d.second << "\n";
            exit(1);
        }
        for(int i=0; i<4; i++) {
            int nextX = d.first.first + option[i].first;
            int nextY = d.first.second + option[i].second;
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
            if(mark[nextX][nextY]) continue;
            if(a[nextX][nextY] == 1) continue;
            int step = d.second+1;
            q.push(make_pair(make_pair(nextX, nextY), step));
            mark[nextX][nextY] = true;
        }
    }
    cout << "-1\n";
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &r, &c);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    option.push_back({1,0}); //xuong
    option.push_back({0,1}); //sang phai
    option.push_back({0,-1}); //sang trai
    option.push_back({-1,0}); //len tren

    solve({r-1, c-1});

    return 0;
}
