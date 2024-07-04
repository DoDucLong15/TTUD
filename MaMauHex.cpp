#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
string a[MAX];
string b[MAX];


int deCode(int m, int c)
{
    if(c >= m) return c-m;
    else {
        return c+256-m;
    }
}

int convertHextoDec(string s)
{
    int e = 1;
    int res = 0;
    for(int i=1; i>=0; i--) {
        if(isdigit(s[i])) {
            res += (s[i]-'0')*e;
            e *= 16;
        }
        else {
            res += (s[i]-'A' + 10)*e;
            e *= 16;
        }
    }
    return res;
}

int main() {

    scanf("%d", &n); getchar();
    for(int i=0; i<n; i++) {
        getline(cin,a[i]); fflush(stdin);
    }
    for(int i=0; i<n; i++) {
        getline(cin, b[i]); fflush(stdin);
    }
    //solve
    set<pair<pair<int,int>,int>> st;
    map<pair<pair<int,int>,int>, int> mp;
    for(int i=0; i<n; i++) {
//        while(a[i].length() < 7) {
//            a[i] += "0";
//        }
//        while(b[i].length() < 7) {
//            b[i] += "0";
//        }
        int rr1 = convertHextoDec(a[i].substr(1,2));
        int rr2 = convertHextoDec(b[i].substr(1,2));
        int gg1 = convertHextoDec(a[i].substr(3,2));
        int gg2 = convertHextoDec(b[i].substr(3,2));
        int bb1 = convertHextoDec(a[i].substr(5,2));
        int bb2 = convertHextoDec(b[i].substr(5,2));
        auto m = make_pair(make_pair(deCode(rr1,rr2), deCode(gg1,gg2)), deCode(bb1,bb2));
        st.insert(m);
        mp[m]++;
    }
    int res = 0;
    for(auto it=st.begin(); it != st.end(); it++) {
        res = max(res, mp[*it]);
    }
    double value = ((double)res/n)*100;
    printf("%.2lf%%", value);

    return 0;
}
