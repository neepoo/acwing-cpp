//
// Created by neepoo on 23-10-24.
//
#include<iostream>
int n, a;
int main() {
    std::cin >> n;
    for (int i = 0; i <n; ++i) {
        std::cin >> a;
        int cnt = 0;
        while (a) {
            a-= a&(-a);
            cnt++;
        }
        std::cout << cnt << " ";
    }
}