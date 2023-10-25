//
// Created by neepoo on 23-10-25.
//
#include <iostream>

const int N = 100010;
int idx = 1, head = -1;
int e[N], ne[N];
int m;

void insertHead(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void insertAt(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void delAt(int k) {
    if (k == 0) {
        head = ne[head];
    } else {
        ne[k] = ne[ne[k]];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        char op;
        std::cin >> op;
        if (op == 'H'){
            int x;
            std::cin >> x;
            insertHead(x);
        }else if(op == 'D'){
            int k;
            std::cin >> k;
            delAt(k);
        } else{
            int k, x;
            std::cin >> k >> x;
            insertAt(k, x);
        }
    }
    for (;head!=-1;head=ne[head]){
        std::cout << e[head] << " ";
    }
}