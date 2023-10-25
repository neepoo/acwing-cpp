//
// Created by neepoo on 23-10-25.
//

#include<iostream>
#include<unordered_map>
#include <vector>

int n;
std::vector<std::string> person;
std::unordered_map<std::string, std::pair<int, int>> haves;
std::unordered_map<std::string, std::vector<std::string>> senders;
std::unordered_map<std::string, int> saves;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    std::string name;
    for (int i = 0; i < n; ++i) {
        std::cin >> name;
        person.emplace_back(name);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> name;
        int amount, cnt;
        std::cin >> amount >> cnt;
        haves[name] = {amount, cnt};
        for (int j = 0; j < cnt; ++j) {
            std::string rc;
            std::cin >> rc;
            senders[name].emplace_back(rc);
        }
    }
    for (auto sender: senders) {
        auto all = haves[sender.first].first;
        auto m = all % haves[sender.first].second;
        saves[sender.first] -= all - m;
        for (auto rc: sender.second) {
            saves[rc] += all / haves[sender.first].second;
        }
    }
    for (auto name: person) {
        std::cout << name << " " << saves[name] << '\n';
    }
}