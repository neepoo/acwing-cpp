//
// Created by neepoo on 23-10-23.
//
#include <iostream>

int n, k;
const int N = 100010;
int a[N];

int quickSelect(int *q, int l, int r, int k) {
    if (l == r) {
        return q[l];
    }
    int x = q[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) std::swap(q[i], q[j]);
    }
    int sl = j - l + 1;
    if (k <= sl) {
        return quickSelect(q, l, j, k);
    }
    return quickSelect(q, j + 1, r, k - sl);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << quickSelect(a, 0, n - 1, k) << std::endl;
    return 0;
}