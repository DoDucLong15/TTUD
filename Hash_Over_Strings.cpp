#include <bits/stdc++.h>
using namespace std;

int n, m;

int solve(string s)
{
    int k = s.length();
    long long p = 1;
    long long result = 0;
    for(int i=k-1; i>=0; i--) {
        result = (result + (s[i]*p))%m;
        p = (p*256)%m;
    }
    cout << result%m << "\n";
}

int main()
{
    scanf("%d%d", &n, &m);
    getchar();
    string s;
    for(int i=0; i<n; i++) {
        getline(cin, s);
        solve(s);
    }
}
