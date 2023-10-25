////
//// Created by neepoo on 23-10-23.
////
#include <iostream>
#include<vector>
#include<unordered_map>

const int mod = 1e9 + 7;

static int a, n;
std::unordered_map<unsigned long long, unsigned long long> m;

auto divisor(int x) -> void {
    for (int i = 2; i <= x / i; ++i) {
        while (x % i == 0) {
            m[i]++;
            x /= i;
        }
    }
    if (x > 1) m[x]++;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        divisor(a);
    }
    unsigned long long res = 1;
    for (std::pair<unsigned long long, unsigned long long> fs: m) {
        unsigned long long t = 1;
        for (int i = 0; i < fs.second; i++) {
            t = (t * fs.first + 1) % mod;
        }
        res = res * t % mod;
    }
    std::cout << res;
}