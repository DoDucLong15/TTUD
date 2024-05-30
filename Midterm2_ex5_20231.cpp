#include <bits/stdc++.h>
using namespace std;

const int Q = 1e9 + 7;
const int MAX = 1e3 + 5;
int n;
int option[3] = {0,1,2};
int cnt = 0, a[MAX]; //luu gia tri

bool check(int x, int k)
{
    if(k == 0) return true;
    if(a[k-1] == 0 && x == 0) return false;
    if(a[k-1] == 1 && x == 1) return false;
    return true;
}

void Try(int k)
{
    for(int i=0; i<3; i++) {
        if(check(option[i], k)) {
            a[k] = option[i];
            if(k == (n-1)) {
                cnt++;
                cnt = cnt%Q;
            }
            else Try(k+1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(0);
    cout << cnt << "\n";

    return 0;
}
