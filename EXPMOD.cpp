#include <bits/stdc++.h>
using namespace std;

const unsigned long long m = 1e9 + 7;
unsigned long long a, b;

unsigned long long exmod(unsigned long long a, unsigned long long b)
{
    a = a%m;
    if(b==1) return a;
    unsigned long long x = exmod(a,b/2);
    x = (x*x)%m;
    if(b%2 == 1) x = (x*a)%m;
    return x;
}

int main()
{
    cin >> a >> b;
//    a %= m;
//    b %= m-1;
    cout << exmod(a, b) << "\n";

    return 0;
}
