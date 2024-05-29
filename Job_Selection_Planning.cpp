#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}

int main()
{
    int c, b;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &c, &b);
        v.push_back({c,b});
        a[i] = 0;
    }
    sort(v.begin(), v.end(), cmp);
//    for(int i=0; i<n; i++) {
//        cout << v[i].first << " " << v[i].second << "\n";
//    }
    int value = 0;
    for(int i=0; i<n; i++) {
        int j = v[i].first - 1;
        while(a[j] != 0 && j >= 0) {
            j--;
        }
        if(j < 0) continue;
        else {
            a[j] = v[i].second;
            value += v[i].second;
        }
    }
    cout << value << "\n";
    return 0;
}
