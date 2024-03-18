/*
Description
There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0.
Input
Line 1 contains n and k (1≤n≤11,1≤k≤10)
 Line i+1 (i=1,2,…,2*n+1) contains the (i−1)
th
 line of the matrix c (rows and columns are indexed from 0,1,2,..,2*n).
Output
Unique line contains the length of the shortest route.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int n, k, C[30][MAX], cmin;
int visited[MAX] = {0};
int road[MAX]; //luu tru hanh trinh iem den
int f_min = INT_MAX, f = 0, load = 0;

bool check(int i, int v)
{
    if (visited[i] == 1) return false;
    if(C[road[v-1]][i] == 0) return false;
    if(i > n) {
        if(visited[i-n] == 0) return false;
    }
    else if(load + 1 > k) return false;
}

void GhiNhan()
{
    f_min = min(f_min, f + C[road[2*n]][road[0]]);
}

void Try(int v)
{
    for(int i=1; i<=2*n; i++) {
        if(check(i, v)) {
            road[v] = i;
            f += C[road[v-1]][road[v]];
            visited[i] = 1;
            if(i <= n) load++;
            else load--;
            if(v==2*n) GhiNhan();
            else if((f + cmin*(2*n-v)) < f_min) Try(v+1);
            if(i <= n) load--;
            else load++;
            visited[i] = 0;
            f -= C[road[v-1]][road[v]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int MIN = INT_MAX;
    scanf("%d%d", &n, &k);
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++) {
            scanf("%d", &C[i][j]);
            if(i != j) MIN = min(MIN, C[i][j]);
        }
    cmin = MIN;
    road[0] = 0;
    Try(1);
    cout << f_min << "\n";

    return 0;
}
