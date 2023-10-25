//
// Created by neepoo on 23-10-20.
//

#include <iostream>


const int N = 100010;
int q, n, k;
int a[N];

int rightMost(const int *arr, int l, int r, int x) {

    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (arr[mid] <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return arr[l] == x ? l : -1;
}

int leftMost(const int *arr, int l, int r, int x) {
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return arr[l] == x ? l : -1;
}


int main() {
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; ++i) {
        std::cin >> k;
        std::cout << leftMost(a, 0, n - 1, k) << " " << rightMost(a, 0, n - 1, k) << std::endl;
    }
    return 0;
}