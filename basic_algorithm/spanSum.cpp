//
// Created by neepoo on 23-10-24.
//
#include<iostream>
#include<vector>
#include <algorithm>

using pair = std::pair<int, int>;
std::vector<int> all;
int sum[300010];
std::vector<pair> op, query;
int n, m;

int find(int x) {
    int l = 0, r = all.size() - 1;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (all[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    int x, c;
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> c;
        op.emplace_back(x, c);
        all.push_back(x);
    }
    int l, r;
    for (int i = 0; i < m; ++i) {
        std::cin >> l >> r;
        query.emplace_back(l, r);
        all.push_back(l);
        all.push_back(r);
    }
    std::sort(all.begin(), all.end());
    all.erase(std::unique(all.begin(), all.end()), all.end());

    for (auto o: op) {
        sum[find(o.first)] += o.second;
    }
    // prefix sum
    for (int i = 1; i <= all.size(); i++) {
        sum[i] += sum[i - 1];
    }
    for (auto q:query) {
        std::cout << sum[find(q.second)] - sum[find(q.first)-1] << '\n';
    }
}
