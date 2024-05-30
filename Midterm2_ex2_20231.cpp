#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int n, m;
int x[MAX], c[MAX][MAX];
map<int,int> mp; //{point, thoi diem tham}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &x[i]);
        mp[x[i]] = i;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) scanf("%d", &c[i][j]);
    scanf("%d", &m);
    int a,b;
    bool ok = true;
    for(int i=0; i<m; i++) {
        scanf("%d%d", &a, &b);
        if(mp[a] > mp[b]) ok = false;
    }
    if(!ok) cout << "-1\n";
    else {
        int sum = 0;
        for(int i=1; i<n; i++) {
            sum += c[x[i]][x[i+1]];
        }
        sum += c[x[n]][x[1]];
        cout << sum << "\n";
    }

    return 0;
}

/*
Testcase 1
4
1 2 3 4
0 2 4 3
3 0 1 1
2 3 0 5
1 3 2 0
3
1 2
3 4
1 4

Testcase 2
4
4 3 2 1
0 2 4 3
3 0 1 1
2 3 0 5
1 3 2 0
3
1 2
3 4
1 4
*/
