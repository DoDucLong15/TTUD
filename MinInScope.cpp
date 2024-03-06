/*
Bài 3. Giá trị nhỏ nhất trong khoảng
Cho 1 đoạn gồm n số nguyên với giá trị a0,. . ., an-1, ta định nghĩa rmq(i, j) là giá trị nhỏ nhất trong đoạn
từ ai tới aj (giá trị số nhỏ nhất trong các số ai, ai+1, . . ., aj).
Ví dụ dãy 10 phần tử 1,5,3,7,8,43,23,5,12,7 thì
• rmq(0,9) = 1
• rmq(1,9)=3
• rmq(3,5)=7
Với đầu vào là m đoạn (i1, j1),. . ., (im, jm), giá trị tổng của các rmq định nghĩa trên m cặp được tính như
sau Q = rmq(i1, j1) + . . . + rmq(im, jm)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	int* a = new int[n];
	for(int i=0; i<n; i++) cin >> a[i];
	//tinh ca day
	int** b = new int*[n];
	for(int i=0; i<n; i++) b[i] = new int[n];
	for(int i=0; i<n; i++) b[i][i] = a[i];
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++) {
			if(b[i][j-1] < a[j]) b[i][j] = b[i][j-1];
			else b[i][j] = a[j];
		}
	//tinh Q
	cin >> m;
	int sum = 0;
	for(int i=0; i<m; i++) {
		int p, q;
		cin >> p >> q;
		sum += b[p][q];
	}
	cout << sum << endl;
	
	delete(a);
	for(int i=0; i<n; i++) delete(b[i]);
	delete(b);
	return 0;
}