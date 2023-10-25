//
// Created by neepoo on 23-10-25.
//
#include<iostream>
#include<unordered_map>

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::unordered_map<int, int> cnt;


bool isLeap(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int days(int year, int month, int day) {
    int res = 0;
    for (int y = 0; y < year; ++y) {
        res += 365 + isLeap(y);
    }

    for (int i = 1; i < month; ++i) {
        res += months[i];
        if (i == 2) {
            res += static_cast<int>(isLeap(year));
        }
    }
    res += day;
    return res;
}

const int base = days(1900, 1, 1);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int year = 1900; year <= 1900 + n - 1; ++year) {
        for (int month = 1; month <= 12; ++month) {
            auto day = days(year, month, 13);
            auto sub = day - base;
            cnt[sub % 7] += 1;
        }
    }
    for (int i = 5;i<12;i++){
        std::cout << cnt[i%7] << " ";
    }
}