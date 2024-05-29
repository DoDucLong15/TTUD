#include <bits/stdc++.h>
using namespace std;

string a, b;
map<char,string> mp;

string multi_string(string s, char c)
{
    if(mp[c] != "") return mp[c];
    //c*s
    int d = 0;
    string result = "";
    int x = c - '0';
    for(int i=s.length()-1; i>=0; i--) {
        int t = s[i] - '0';
        t = t*x + d;
        result += to_string(t%10);
        d = t/10;
    }
    if(d != 0) result += to_string(d);
    reverse(result.begin(), result.end());
    mp[c] = result;
    return result;
}

string add_string(string s1, string s2)
{
    //s1 + s2
    int i = s1.length()-1, j = s2.length()-1;
    int d = 0;
    string result = "";
    while(i >=0 && j >= 0) {
        int x = s1[i] - '0';
        int y = s2[j] - '0';
        int t = x + y + d;
        result += to_string(t%10);
        d = t/10;
        i--;
        j--;
    }
    while(i >= 0) {
        int x = s1[i] - '0';
        int t = x + d;
        result += to_string(t%10);
        d = t/10;
        i--;
    }
    while(j >= 0) {
        int y = s2[j] - '0';
        int t = y + d;
        result += to_string(t%10);
        d = t/10;
        j--;
    }
    if(d != 0) result += to_string(d);
    reverse(result.begin(), result.end());
    return result;
}

void solve(string s1, string s2)
{
    string result = "0";
    int length1 = s1.length();
    for(int i=length1-1; i>=0; i--) {
        string temp = multi_string(s2, s1[i]);
        string p(length1-i-1,'0');
        temp += p;
        result = add_string(result,temp);
    }
    cout << result << "\n";
}

int main()
{
    getline(cin, a);
    getline(cin, b);
    solve(a, b);

    return 0;
}
