#include <iostream>
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
    int m = matrix.size(), n = matrix[0].size();
    int** a = new int*[m+1];
    for(int i=0; i<=m; i++) a[i] = new int[n+1];
    for(int i=0; i<=m; i++) a[i][0] = 0;
    for(int j=0; j<=n; j++) a[0][j] = 0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + matrix[i-1][j-1];

}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<vector<int> > v;
    int m, n, a, k;
    scanf("%d", &m, &n);
    for(int i=0; i<m; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            scanf("%d", &a);
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    scanf("%d", &k);

    cout << maxSumSubmatrix(v, k) << "\n";

    return 0;
}
