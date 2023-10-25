//
// Created by neepoo on 23-10-20.
//

#include <iostream>

const int N = 1000010;

void quickSort(int *q, int l, int r) {
    if (l >= r) return;
    auto mid = q[(l + r) / 2];
    auto i = l - 1, j = r + 1;
    while (i < j) {
        // 这样写的原因是无论交换与否，i,j都会继续前进
        while (q[++i] < mid);
        while (q[--j] > mid);
        if (i < j) {
            std::swap(q[i], q[j]);
        }
    }
    quickSort(q, l, j);
    quickSort(q, j + 1, r);
}

int n, a[N];

int main(int argc, char **argv) {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}