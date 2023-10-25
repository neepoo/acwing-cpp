//
// Created by neepoo on 23-10-24.
//
#include <iostream>

const int N = 1e5 + 10;

int a[N], b[N];
int n, m;

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    int i = 0, j= 0;
    for (; i < n && j < m; ) {
        if (a[i] == b[j]){
            i++;
            j++;
        } else{
            j++;
        }
    }
    bool res;
    res = ((i==n) && b[j-1]==a[n-1]);
    if (res){
        std::cout << "Yes";
    }else{
        std::cout << "No";
    }
}