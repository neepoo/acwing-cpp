//
// Created by neepoo on 11/5/23.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 510;
const int MAX = 0x3f3f3f3f;
int g[N][N], d[N];
bool st[N];
int n, m, u, v, w;

int prim() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || d[j] < d[t])) {
                t = j;
            }
        }
        if (i && d[t] == MAX) {
            return MAX;
        }
        st[t] = true;
        if (i) {
            res += d[t];
        }
        for (int j = 1; j <= n; j++) {
            if (d[j] > g[t][j]) d[j] = g[t][j];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(g[0], g[0] + N * N, MAX);
    fill(d, d + N, MAX);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int t = prim();
    if (t == MAX)
        cout << "impossible";
    else
        cout << t;
}