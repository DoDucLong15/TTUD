#include <bits/stdc++.h>
using namespace std;

int last[256];

void computeLast(string p)
{
    for(int c=0; c<=255; c++) last[c] = 0;
    for(int i=p.length()-1; i>=0; i--) {
        if(last[p[i]] == 0) last[p[i]] = i;
    }
}

int boyerMoore(string p, string t)
{
    computeLast(p);
    int s = 0; //do truot
    int cnt = 0; //dem ket qua
    int n = t.length(), m = p.length();
    while(s <= (n-m)) {
        int j = m-1;
        while(j>=0 && p[j] == t[s+j]) {
            j--;
        }
        if(j == -1) {
            cnt++;
            s++;
        }
        else {
            int k = last[t[s+j]];
            s = s + (j - k > 1 ? j-k:1);
        }
    }
    return cnt;
}

int main()
{
    string p, t;
    getline(cin, p);
    getline(cin, t);

    cout << boyerMoore(p, t) << "\n";

    return 0;
}
