#include <bits/stdc++.h>
using namespace std;

int max_rectangle(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> heights(m + 1, 0);
    int max_area = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            heights[j] = matrix[i][j] == 1 ? heights[j] + 1 : 0;
        }

        stack<int> s;
        s.push(-1);

        for (int j = 0; j <= m; ++j) {
            while (s.top() != -1 && heights[j] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = j - 1 - s.top();
                max_area = max(max_area, h * w);
            }
            s.push(j);
        }
    }

    return max_area;
}

// Test the function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> matrix;
    int n, m, a;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<m; j++) {
            scanf("%d", &a);
            temp.push_back(a);
        }
        matrix.push_back(temp);
    }

    cout << max_rectangle(matrix) << endl;
    return 0;
}

