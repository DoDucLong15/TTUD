#include <bits/stdc++.h>
using namespace std;

const int MAX = 400040;

int maxVal[MAX];

void UpdateFromNode(int id, int L, int R, int index, int value)
{
    if(L > R) return;
    if(index < L || index > R) return;
    if(L == R) {
        maxVal[id] = value;
        return;
    }
    int LC = 2*id, RC = 2*id + 1;
    int m = (L+R)/2;
    UpdateFromNode(LC, L, m, index, value);
    UpdateFromNode(RC, m+1, R, index, value);
    maxVal[id] = max(maxVal[LC], maxVal[RC]);
}

int GetMaxFromNode(int id, int L, int R, int i, int j)
{
    if(i > R || j < L) return INT_MIN;
    if(i <= L && j >= R) return maxVal[id];
    int middle = (L + R)/2;
    int LC = 2*id, RC = 2*id+1;
    int maxLeft = GetMaxFromNode(LC, L, middle, i, j);
    int maxRight = GetMaxFromNode(RC, middle+1, R, i, j);
    return max(maxLeft, maxRight);
}

int main()
{
    int temp, k1, k2, n, m;
    string request, num1, num2, s;

    scanf("%d", &n); getchar();
    for(int i=1; i<=n; i++) {
        scanf("%d", &temp); getchar();
        UpdateFromNode(1, 1, n, i, temp);
    }

    //request
    scanf("%d", &m); getchar();
    for(int i=0; i<m; i++) {
        getline(cin, s);
        stringstream ss(s);
        ss >> request >> k1 >> k2;
        if(request == "get-max") cout << GetMaxFromNode(1, 1, n, k1, k2) << "\n";
        else if(request == "update") UpdateFromNode(1, 1, n, k1, k2);
    }

    return 0;
}
