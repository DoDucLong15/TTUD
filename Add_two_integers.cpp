#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull a, b;

int main()
{
    cin >> a >> b;
    ull d = a%10;
    a = a/10;
    ull c = b%10;
    b = b/10;
    ull t = d + c;
    ull sum = a+b;
    if(t >= 10) {
        sum += 1;
        t = t%10;
    }
    if(sum != 0) cout << sum << t << "\n";
    else cout << t << "\n";

    return 0;
}
