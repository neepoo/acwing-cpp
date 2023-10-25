//
// Created by neepoo on 23-10-20.
//
#include <iostream>
#include <iomanip>

int main() {
    double x;
    std::cin >> x;
    double l = -10000.0, r = 10000.0;
    double mid;
    while (r - l >= 1e-8){
        mid = (l + r) / 2;
        if ( mid * mid * mid >= x ) {
            r = mid;
        } else{
            l = mid;
        }
    }
    std::cout << std::fixed << std::setprecision(6) << l;
    return 0;
}