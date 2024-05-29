#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 +7;
int n, value[1005];

//danh sach tu 0 den n-2
int solve(int n, int sum)
{
    if(n<=0) return 0;
    if(sum<0) return 0;
    if(sum==0) return 1;
    return (solve(n, sum-value[n-1]) + solve(n-1, sum))%M;
}
//giong bai toan tien
//value la danh sach cac so co the phan tich

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n-1; i++) value[i] = i+1;
    cout << (solve(n-1, n) + 1)%M << "\n";

    return 0;
}
