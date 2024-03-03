/*
Bài 4. Tìm hình chữ nhật tạo nên bởi các bit 1 có diện tích lớn nhất
Một hình chữ nhật kích thước n x m được cấu tạo từ các ô con điền giá trị là 0 hoặc là 1. Hãy tìm hình
chữ nhật được tạo nên bằng các bit 1 có diện tích lớn nhất.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][m], b[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) cin >> a[i][j];
	b[0][0] = a[0][0];
	for(int j=1; j<m; j++) b[0][j] = b[0][j-1] + a[0][j];
	for(int i=1; i<n; i++) b[i][0] = b[i-1][0] + a[i][0];
	for(int i=1; i<n; i++)
		for(int j=1; j<m; j++) b[i][j] = b[i][j-1] + b[i-1][j] - b[i-1][j-1] + a[i][j];
	int max = b[0][m-1] > b[n-1][0] ? b[0][m-1] : b[n-1][0];
	for(int j=1; j<m; j++) {
		int d = j+1, i=1;
		while(i < n) {
			int area = 0;
			while(b[i][j]-b[i-1][j] == d) {
				area += d;
				i++;
			}
			if(area > max) max = area;
			i++;
		}
	}
	cout << max << endl;
	
	return 0;
}