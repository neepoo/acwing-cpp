//
// Created by neepoo on 23-10-24.
//
#include <iostream>
#include<vector>
#include<algorithm>

const int N = 100010;
int n;

int merge(std::vector<std::pair<int, int>> &ps) {
    int st = -2e9, ed = -2e9;
    int cnt = 0;
    for(auto p: ps) {
        if (st == -2e9){
            st = p.first;
            ed = p.second;
            cnt++;
        }
        if (p.first <= ed){
            ed = std::max(ed, p.second);
        } else{
            st = p.first;
            ed = p.second;
            cnt++;
        }
    }
    return cnt;

}

int main() {
    std::cin >> n;
    std::vector<std::pair<int, int>> ps;
    int l, r;
    for (int i = 0; i < n; ++i) {
        std::cin >> l >> r;
        ps.push_back({l, r});
    }
    std::sort(ps.begin(), ps.end());
    std::cout << merge(ps) << '\n';
}