#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
int m, n, k;
int v[MAX][MAX];
int conflict[MAX][MAX];
map<int, vector<int>> object; //{giao vien, danh sach mon hoc}
vector<int> size_object;
int res = INT_MAX, max_object = INT_MIN;

//void build()
//{
//    for(int i=0; i<m; i++)
//        for(int j=1; j<=n; j++) v[i][j] = 0;
//}

bool check(int i, int t)
{
    if(v[i][t] != 1) return false;
    for(auto x : object[i])
        if(conflict[x][t]==1) return false;
    return true;
}

void GhiNhan()
{
    int max_e = *max_element(size_object.begin(), size_object.end());
    res = min(res, max_e);
}

void Try(int t)
{
    for(int i=0; i<m; i++) {
        if(check(i, t)) {
            object[i].push_back(t);
            size_object[i]++;
            int temp = max_object;
            max_object = max(max_object, size_object[i]);
            if(t==n) GhiNhan();
            else if(max_object < res) Try(t+1);
            object[i].pop_back();
            size_object[i]--;
            max_object = temp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d%d", &m, &n);
//    build();
    int a;
    for(int i=0; i<m; i++) {
        scanf("%d", &k);
        for(int j=0; j<k; j++) {
            scanf("%d", &a);
            v[i][a] = 1;
        }
        size_object.push_back(0);
    }
    scanf("%d", &k);
    int p, q;
    for(int i=0; i<k; i++) {
        scanf("%d%d", &p, &q);
        conflict[p][q] = 1;
        conflict[p][p] = 1;
        conflict[q][p] = 1;
        conflict[q][q] = 1;
    }

    Try(1);
    cout << res << "\n";

    return 0;
}
