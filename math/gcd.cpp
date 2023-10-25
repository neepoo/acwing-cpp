//
// Created by neepoo on 23-10-24.
//
#include<iostream>

int n, a, b;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        std::cout << gcd(a, b) << '\n';
    }
}