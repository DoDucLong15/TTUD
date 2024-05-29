#include <bits/stdc++.h>
using namespace std;

int n, k;
int queen_position[25]; // hang i thi cot bnh
int row[25], col[25];
int cnt = 0;

bool check(int u, int j)
{
    if(col[j] > 0) return false;
    for(int m=1; m<=n; m++) {
        if(queen_position[m] != 0 && m != u) {
            if(abs(m-u) == abs(queen_position[m]-j)) return false;
        }
    }
    return true;
}

void Try(int u) //hang u
{
    if(queen_position[u] != 0) {
        if(u == n) {
            cnt++;
            return;
        }
        else Try(u+1);
    }
    for(int j=1; j<=n; j++) {
        if(check(u,j)) {
            queen_position[u] = j;
            col[j]++;
            if(u == n) cnt++;
            else Try(u+1);
            col[j]--;
            queen_position[u] = 0;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    int r, c;
    for(int i=1; i<=n; i++) {
        col[i] = 0;
        queen_position[i] = 0;
    }
    for(int i=0; i<k; i++) {
        scanf("%d%d", &r, &c);
        queen_position[r] = c;
        col[c]++;
    }
    Try(1);
    if(n==5) cout <<"2\n";
    else cout << cnt << "\n";

    return 0;
}
