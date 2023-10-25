//
// Created by neepoo on 23-10-24.
//
#include<iostream>

#define ull unsigned long long;
int n;
using u64 = unsigned long long;


u64 mi(u64 a, u64 b, u64 c) {
    u64 res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % c;
        }
        b >>= 1;
        a = a * a % c;
    }

    return res;
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        u64 a, b, c;
        std::cin >> a >> b >> c;
        std::cout << mi(a, b, c) << std::endl;
    }
}
