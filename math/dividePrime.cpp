//
// Created by neepoo on 23-10-23.
//
#include <iostream>

auto dividePrime(int x) -> void {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            std::cout << i << " " << cnt << '\n';
        }
    }
    if (x > 1) {
        std::cout << x << " " << 1 << '\n';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, a;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        dividePrime(a);
    }
}