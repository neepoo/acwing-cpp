//
// Created by neepoo on 11/4/23.
//
#include <queue>
#include <iostream>

using namespace std;

const int N = 150010;
int n, m, x, y, z;
int h[N], e[N], ne[N], W[N], d[N], st[N], idx;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;


void add(int a, int b, int c) {
    e[idx] = b;
    W[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    fill(h, h + N, -1);
    fill(d, d + N, 0x3f3f3f3f);
    while (m--) {
        cin >> x >> y >> z;
        add(x, y, z);
    }

    q.emplace(0, 1);
    d[1] = 0;
    while (!q.empty()) {
        auto [a, b] = q.top();
        q.pop();
        if (st[b]) continue;
        st[b] = true;
        for (int i = h[b]; i != -1; i = ne[i]) {
            auto j = e[i];
            auto wi = W[i];
            if (a + wi < d[j]){
                d[j] = a + wi;
                q.emplace(d[j], j);
            }
        }
    }
    auto dis = d[n];
    cout << (dis==0x3f3f3f3f?-1:dis);
}