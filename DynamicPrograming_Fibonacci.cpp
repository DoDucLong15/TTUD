#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int mem[MAX];

int fibonacci(int n)
{
    if(n==1 || n==2) return 1;
    if(mem[n] != -1) return mem[n];
    else {
        int a = fibonacci(n-1) + fibonacci(n-2);
        mem[n] = a;
        return a;
    }
}

int main()
{
    memset(mem, -1, sizeof(mem));
    for(int i=0; i<50; i++) cout << fibonacci(i) << " ";

    return 0;
}
