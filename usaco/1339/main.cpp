//
// Created by neepoo on 23-10-25.
//
#include <iostream>

const int mod = 47;
std::string ufo, team;

auto cal(const std::string& s) -> int {
    auto res = 1;
    for (auto c:s){
        res = res *(c-'A' +1) % mod;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> ufo >> team;
    std::cout << (cal(ufo)== cal(team)?"GO":"STAY");
}