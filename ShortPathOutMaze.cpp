/*
Bài 2. Tìm đường ngắn nhất thoát khỏi mê cung
Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó
• A[i,j] = 1 thể hiện ô (i,j) là tường gạch
• và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào.
Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu
ô đó là ô trống. Để thoát khỏi mê cung chỉ cần đi ra được tới biên là xong. Xuất phát từ 1 ô trống trong
mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.
*/

#include <bits/stdc++.h>
using namespace std;

struct point
{
    int r;
    int c;
    int step;
};

int shortPath(int a[][999], int n, int m, int r, int c)
{
    queue<point> q;
    point p;
    p.r = r; p.c = c; p.step = 0;
    q.push(p);
    set<pair<int,int>> st;
    st.insert({r, c});
    while(!q.empty()) {
        point temp = q.front();
        point t;
        int size;
        q.pop();
        if(temp.r == 0 || temp.r == n-1 || temp.c == 0 || temp.c == m-1) return temp.step;
        int temp_R = temp.r, temp_C = temp.c;
        if(a[temp_R-1][temp_C] == 0) {
        	size = st.size();
        	st.insert({temp_R-1, temp_C});
        	if(st.size() != size) {
        		t.r = temp_R-1;
	            t.c = temp_C;
	            t.step = temp.step + 1;
	            q.push(t);
			}
        }
        if(a[temp_R+1][temp_C] == 0) {
            size = st.size();
        	st.insert({temp_R+1, temp_C});
        	if(st.size() != size) {
        		t.r = temp_R+1;
	            t.c = temp_C;
	            t.step = temp.step + 1;
	            q.push(t);
			}
        }
        if(a[temp_R][temp_C-1] == 0) {
            size = st.size();
        	st.insert({temp_R, temp_C-1});
        	if(st.size() != size) {
        		t.r = temp_R;
	            t.c = temp_C-1;
	            t.step = temp.step + 1;
	            q.push(t);
			}
        }
        if(a[temp_R][temp_C+1] == 0) {
            size = st.size();
        	st.insert({temp_R, temp_C+1});
        	if(st.size() != size) {
        		t.r = temp_R;
	            t.c = temp_C+1;
	            t.step = temp.step + 1;
	            q.push(t);
			}
        }
    }
    return -1;
}

int main()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int a[n][999];
//    int** a = new int*[n];
//    for(int i=0; i<n; i++) a[i] = new int[m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> a[i][j];
    cout << shortPath(a, n, m, r-1, c-1) << endl;

    return 0;
}
