#include <bits/stdc++.h>
using namespace std;

const int Q = 1e9 + 7;
const int MAX = 1e3;
int n;
int mem[MAX], mem0[MAX], mem1[MAX], mem2[MAX];

long long solve(int i);
long long solve1(int i);
long long solve2(int i);
long long solve0(int i)
{
    if(i==1) return mem0[i] = 1;
    if(mem0[i] != -1) return mem0[i]%Q;
    return mem0[i] = (solve1(i-1)%Q + solve2(i-1)%Q)%Q;
}

long long solve1(int i)
{
    if(i==1) return mem1[i] = 1;
    if(mem1[i] != -1) return mem1[i]%Q;
    return mem1[i] = (solve0(i-1)%Q + solve2(i-1)%Q)%Q;
}

long long solve2(int i)
{
    if(i==1) return mem2[i] = 1;
    if(mem2[i] != -1) return mem2[i]%Q;
    return mem2[i] = solve(i-1)%Q;
}

long long solve(int i)
{
    if(mem[i] != -1) return mem[i]%Q;
    return mem[i] = (solve0(i)%Q + solve1(i)%Q + solve2(i)%Q)%Q;
}

int main()
{
    memset(mem, -1, sizeof(mem));
    memset(mem0, -1, sizeof(mem0));
    memset(mem1, -1, sizeof(mem1));
    memset(mem2, -1, sizeof(mem2));
    scanf("%d", &n);
    cout << solve(n)%Q << "\n";

    return 0;
}

