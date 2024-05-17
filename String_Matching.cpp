#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0;
    string p, t;
    getline(cin, p);
    getline(cin, t);

    auto pos = t.find(p);
    while(pos != string::npos) {
        cnt++;
        pos = t.find(p, pos + p.length());
    }

    cout << cnt << "\n";

    return 0;
}
