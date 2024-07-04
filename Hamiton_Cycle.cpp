#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int T;
int n, m;
int deg[MAX];

int main()
{
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        scanf("%d%d", &n, &m);
        //init
        for(int i=1; i<=n; i++) deg[i] = 0;
        for(int j=0; j<m; j++) {
            int a, b;
            scanf("%d%d", &a, &b);
            deg[a]++;
            deg[b]++;
        }
        bool check = true;
        int condition = n/2;
        for(int i=1; i<=n; i++) {
            if(deg[i] < condition) {
                check = false;
                break;
            }
        }
        if(check) cout << "1\n";
        else cout << "0\n";
    }
}
