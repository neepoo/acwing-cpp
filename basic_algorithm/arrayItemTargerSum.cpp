//
// Created by neepoo on 23-10-24.
//
/*
 * 给定两个升序排序的有序数组 A
 和 B
，以及一个目标值 x
。

数组下标从 0
 开始。

请你求出满足 A[i]+B[j]=x
 的数对 (i,j)
。

数据保证有唯一解。

输入格式
第一行包含三个整数 n,m,x
，分别表示 A
 的长度，B
 的长度以及目标值 x
。

第二行包含 n
 个整数，表示数组 A
。

第三行包含 m
 个整数，表示数组 B
。

输出格式
共一行，包含两个整数 i
 和 j
。

数据范围
数组长度不超过 105
。
同一数组内元素各不相同。
1≤数组元素≤109
输入样例：
4 5 6
1 2 4 7
3 4 6 8 9
输出样例：
1 1
 */
#include <iostream>

const int N = 1e5 + 10;
int n, m, x;
int A[N], B[N];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> B[i];
    }
    int l = 0, r = m - 1;
    while (l < n || r >= 0) {
        int t = A[l] + B[r];
        if (t < x) {
            l++;
        } else if (t == x) {
            std::cout << l << " " << r << '\n';
            break;
        } else {
            r--;
        }
    }
}