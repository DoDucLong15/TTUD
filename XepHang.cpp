#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, Q;
    std::cin >> N >> Q;

    std::deque<int> students(N);

    for(int i=0; i<N; i++) {
        std::cin >> students[i];
    }

    for(int i=0; i<Q; i++) {
        int height;
        std::cin >> height;
        auto it = std::upper_bound(students.begin(), students.end(), height);
        students.insert(it, height);
        std::cout << std::distance(students.begin(), it) + 1 << "\n";
    }

    return 0;
}
