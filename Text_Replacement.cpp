#include <bits/stdc++.h>
using namespace std;

string p1, p2;
vector<string> T;

void solve(string s)
{
    auto pos = s.find(p1);
    while(pos != string::npos) {
        s.replace(pos, p1.length(), p2);
        pos = s.find(p1, pos + p2.length());
    }
    cout << s << "\n";
}

int main()
{
    getline(cin, p1);
    getline(cin, p2);
    string s;
    getline(cin, s);
//    while(s != "###") {
//        solve(s);
//        getline(cin, s);
//    }
    solve(s);
    getline(cin, s);
}
