#include <bits/stdc++.h>
using namespace std;

const int Q = INT_MAX;

int hashCode(string p)
{
    int c = 0;
    for(int i=0; i<p.length(); i++) {
        c = c*256 + p[i];
        c = c%Q;
    }
    return c;
}

int hashCode(string s, int start, int end)
{
    int c = 0;
    for(int i=start; i<=end; i++) {
        c = c*256 + s[i];
        c = c%Q;
    }
    return c;
}

int rabinKarp(string p, string t)
{
    int cnt = 0; //result
    int n = t.length(), m = p.length();
    //pow(256, m-1)
    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * 256) % Q;

    int codeP = hashCode(p);
    int codeT = hashCode(t, 0, m-1);
    for(int s=0; s<=(n-m); s++) {
        if(codeP == codeT) {
            bool ok = true;
            for(int j=0; j<m; j++) {
                if(p[j] != t[s+j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) cnt++;
        }
        int d = (t[s]*h);
        d = d%Q;
        d = (codeT - d)%Q;
        codeT = (d*256 + t[s+m])%Q;
    }
    return cnt;
}

int main()
{
    string p, t;
    getline(cin, p);
    getline(cin, t);

    cout << rabinKarp(p, t) << "\n";
    return 0;
}

