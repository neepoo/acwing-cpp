//
// Created by neepoo on 23-10-24.
//
#include<iostream>
#include<array>
#include<algorithm>
const int N = 100010;
int n, q[N];
std::array<int, N> cnt;
int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
    }
    int res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        cnt[q[i]]++;
        while (cnt[q[i]] > 1) {
            cnt[q[j++]]--;
        }
        res = std::max(res, i - j + 1);
    }
    std::cout << res;
}