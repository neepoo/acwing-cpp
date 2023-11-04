//
// Created by neepoo on 11/5/23.
//
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct edge {
    int a, b, c;
};

const int N = 100010;
const int M = 2 * N;

int n, m;
int h[N], p[N], e[M], ne[M], w[M], idx;


int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        p[i] = i;
    }
    vector<edge> es(m);
    for (int i = 0; i < m; ++i) {
        cin >> es[i].a >> es[i].b >> es[i].c;
    }
    // sort by c
    sort(es.begin(), es.end(), [](const edge &a, const edge &b) {
        return a.c < b.c;
    });
    int res = 0;
    int cnt = 0;
    for (auto item: es) {
        int a = item.a;
        int b = item.b;
        int c = item.c;
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            res += c;
            cnt++;
            p[pa] = pb;
        }
    }
    if (cnt != n - 1) {
        cout << "impossible";
    } else {
        cout << res;
    }
}