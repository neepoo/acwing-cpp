//
// Created by neepoo on 11/3/23.
// 给定一个整数 n
//，将数字 1∼n
// 排成一排，将会有很多种排列方法。
//
//现在，请你按照字典序将所有的排列方法输出。

#include<iostream>

const int N = 10;

int path[N], st[N];
int n;

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; i++) {
            std::cout << path[i] << " ";
        }
        std::cout << '\n';
    }
    for (int j = 1; j <= n; ++j) {
        if (!st[j]) {
            path[u] = j;
            st[j] = 1;
            dfs(u + 1);
            st[j] = 0;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    dfs(1);

}
