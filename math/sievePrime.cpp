//
// Created by neepoo on 23-10-23.
//
#include<iostream>
#include<vector>

const int N = 10000010;
int n;
int cnt;
std::vector<bool> st(N, false);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            // 埃式筛
            cnt++;
            for (int j = i; j <= n; j += i) {
                st[j] = true;
            }
        }
    }
    std::cout << cnt;
}