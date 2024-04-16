#include <bits/stdc++.h>
using namespace std;

int n, L;
string s;

string generation(string s)
{
    int length = s.length();
    string result = s;
    if(length < L) {
        for(int i=0; i<(L-length); i++) result = "0" + result;
    }
    return result;
}

int main()
{
    scanf("%d%d", &n, &L);
    getchar();
    for(int i=0; i<n; i++) {
        getline(cin, s);
        cout << generation(s) << "\n";
    }

    return 0;
}
