//
// Created by neepoo on 23-10-23.
//
#include <iostream>

auto checkPrime(int x) -> bool {
    if (x < 2)return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        checkPrime(x) ? std::cout << "Yes\n" : std::cout << "No\n";
    }
}