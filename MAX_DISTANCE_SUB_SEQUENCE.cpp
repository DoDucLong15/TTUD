#include <bits/stdc++.h>
using namespace std;

const int MAX = 100010;
int test_number, n, c;
int a[MAX], kmax, k, result = INT_MIN;
int uv[2];
set<int> s;

void GhiNhan()
{
    kmax = min(kmax, a[c-1]-a[c-2]);
    result = max(result, kmax);
}

void Try(int v)
{
    if(s.empty()) {
        return;
    }
    int e = 0;
    int d = a[v-1] + k;
    auto it = s.lower_bound(d);

    std::set<int>::iterator q;
    if(it != s.end()) {
        if(it != s.begin()) {
            auto prev_it = prev(it); //tiem tang bug
            q = ((*it-d) < (d-*prev_it)) ? it : prev_it;
        }
        else q = it;
        if(q != s.begin()) {
            uv[e++] = *q;
            uv[e++] = *prev(q);
        }
        else {
            uv[e++] = *q;
        }
    }
    else {
        auto prev_it = prev(it);
        q = prev_it;
        uv[e++] = *q;
        if(s.size()>1) uv[e++] = *prev(q);
    }
    for(int i=0; i<e; i++) {
        int temp = uv[i];
        int p = kmax;
        a[v] = temp;
        s.erase(temp);
        kmax = min(kmax, a[v]-a[v-1]);
        if(v == (c-2)) GhiNhan();
        else Try(v+1);
        s.insert(temp);
        kmax = p;
    }
}

int main()
{
    scanf("%d", &test_number);
    for(int i=0; i<test_number; i++) {
        int temp;
        scanf("%d%d", &n, &c);
        for(int j=0; j<n; j++) {
            scanf("%d", &temp);
            s.insert(temp);
        }
        a[0] = *s.begin();
        a[c-1] = *s.rbegin();
        s.erase(a[0]);
        s.erase(a[c-1]);
        k = (a[c-1]-a[0])/(c-2);
        kmax = k;

        Try(1);
        cout << result << "\n";

        result = INT_MIN;
        s.clear();
    }
}
