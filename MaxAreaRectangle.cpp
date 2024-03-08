/*
Bài 4. Tìm hình chữ nhật tạo nên bởi các bit 1 có diện tích lớn nhất
Một hình chữ nhật kích thước n x m được cấu tạo từ các ô con điền giá trị là 0 hoặc là 1. Hãy tìm hình
chữ nhật được tạo nên bằng các bit 1 có diện tích lớn nhất.
*/

#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int n, m;
int a[MAX][MAX], b[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) scanf("%d", &a[i][j]);
	for(int j=0; j<=m; j++) b[0][j] = 0;
	for(int i=0; i<=n; i++) b[i][0] = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) b[i][j] = b[i][j-1] + b[i-1][j] - b[i-1][j-1] + a[i-1][j-1];
	int max = 0;
	for(int j=1; j<=m; j++) {
		int d = j, i=1, k=0;
		while(k < j) {
			while(i <= n) {
				int area = 0;
				while(b[i][j]-b[i-1][j]-b[i][k]+b[i-1][k] == d) {
					area += d;
					i++;
				}
				if(area > max) max = area;
				i++;
			}
			k++;
			d--;
			i=1;
		}
	}
	cout << max << "\n";
}