//
// Created by neepoo on 23-10-25.
//
#include <iostream>

const int N = 1000010;
int n, k, x, a[N];
int q[N], h, t = -1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        a[i] = x;
    }

    for (int i = 0; i < n; ++i) {
        if (i - k + 1 > q[h]) { h++; }
        while (t >= h && a[i] <= a[q[t]]) { t--; }
        q[++t] = i;
        if (i - k + 1 >= 0) {
            std::cout << a[q[h]] << " ";
        }
    }
    std::cout << '\n';
    h = 0, t = -1;
    for (int i = 0; i < n; ++i) {
        if (i - k + 1 > q[h]) { h++; }
        while (t >= h && a[i] >= a[q[t]]) { t--; }
        q[++t] = i;
        if (i - k + 1 >= 0) {
            std::cout << a[q[h]] << " ";
        }
    }
}