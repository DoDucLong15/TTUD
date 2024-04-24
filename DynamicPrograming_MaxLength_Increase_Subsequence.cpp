#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int n, a[MAX];
int mem[MAX];

int LIS(int i)
{
    if(i == 1) return 1;
    if(mem[i] != -1) return mem[i];

    int res = 1;
    for(int j=1; j<i; j++) {
        if(a[j] < a[i]) res = max(res, 1 + LIS(j));
    }
    mem[i] = res;

    return res;
}

int Trace_recursive(int position)
{
    for(int j=1; j<position; j++) {
        if(a[j] < a[position] && mem[position] == mem[j] + 1) {
            Trace_recursive(j);
            break;
        }
    }
    cout << a[position] << " ";
}

int Trace_loop(int position)
{
    stack<int> st;
    st.push(a[position]);
    int _max = mem[position];
    int res = 1;
    while(res < _max) {
        for(int j=1; j<position; j++) {
            if(a[j] < a[position] && mem[position] == mem[j] + 1) {
                res++;
                position = j;
                st.push(a[position]);
                break;
            }
        }
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    memset(mem, -1, sizeof(mem));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    LIS(n);
    int position = 1;
    for(int i=2; i<=n; i++) {
        if(mem[i] > mem[position]) position = i;
    }
    cout << mem[position] << "\n";
    Trace_recursive(position);
    cout << "\n";
    Trace_loop(position);

    return 0;
}
