//
// Created by neepoo on 11/4/23.
//

#include <iostream>

const int N = 510;
static const int MAX = 0x3f3f3f3f;
int n, m, x, y, z;
int g[N][N], d[N], st[N];
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    // init g with full 0x3f3f3f3f;
    fill(g[0], g[0] + N * N, MAX);
    fill(d, d + N, MAX);
    while (m--) {
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }

    d[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        int t = -1;

        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (t==-1 || d[j] < d[t])){
                t = j;
            }
        }
        st[t] = true;
        // relax
        for (int k = 1; k <= n; ++k) {
            if (d[k] > d[t] + g[t][k]){
                d[k] = d[t] + g[t][k];
            }
        }
    }
    cout << (d[n]==MAX?-1:d[n]);
}