//
// Created by neepoo on 11/3/23.
//


#include <iostream>

const int N = 110;

int n;
// 用来判断第i行的皇后在哪一列
int g[N];

bool check(int r, int c);

void dfs(int u) {
    if (u > n) {
        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= n; ++c) {
                std::cout << (g[r] == c ? 'Q' : '.');
            }
            std::cout << '\n';

        }
        std::cout << '\n';
        return;
    }
    // 枚举第u行的皇后放在哪一列
    for (int c = 1; c <= n; ++c) {
        if (check(u, c)) {
            g[u] = c;
            dfs(u + 1);
        }
    }

}

bool check(int r, int c) {
    for (int i = 1; i < r; i++) {
        if (g[i] == c || std::abs(r - i) == std::abs(c - g[i])) return false;

    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    dfs(1);
}