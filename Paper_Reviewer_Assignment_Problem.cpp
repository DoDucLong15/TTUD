#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, m, b;
vector<set<int>> l;

int main()
{
    scanf("%d%d%d", &n, &m, &b);
    int k, tmp;
    for(int i=0; i<n; i++) {
        scanf("%d", &k);
        set<int> st;
        for(int j=0; j<k; j++) {
            scanf("%d", &tmp);
            st.insert(tmp);
        }
        l.push_back(st);
    }
}
