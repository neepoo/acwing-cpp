//
// Created by neepoo on 23-10-25.
//
#include <iostream>

const int N = 100010;
int m;
int q[N], hh, tt = -1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::string op ;
        std::cin >> op;
        if (op == "push"){
            int x;
            std::cin >> x;
            q[++tt]=x;
        }else if (op == "pop"){
            hh++;
        }else if(op == "empty"){
            std::cout << ((hh>tt)?"YES\n":"NO\n");
        } else{
            std::cout << q[hh] << '\n';
        }
    }
}