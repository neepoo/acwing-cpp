//
// Created by neepoo on 23-10-25.
//

#include <iostream>

const int N = 100010;
int n;
int stk[N], tt;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    int x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        while (tt > 0 && stk[tt] >= x) {
            tt--;
        }
        if (tt) {
            std::cout << stk[tt] << " ";
        } else {
            std::cout << -1 << " ";
        }
        stk[++tt] = x;
    }
}