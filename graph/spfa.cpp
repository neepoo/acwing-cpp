//
// Created by neepoo on 11/5/23.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 100010;
const int MAX = 0x3f3f3f3f;
int n, m;
int d[N];
bool st[N];
int h[N], e[N], ne[N], w[N], idx;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(d + 1, d + n + 1, MAX);
    fill(h + 1, h + n + 1, -1);
    int a;
    int b;
    int c;
    while (m--) {
        cin >> a >> b >> c;
        add(a, b, c);
    }

    d[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int i = h[head]; i != -1; i = ne[i]) {
            int j = e[i];
            int wi = w[i];
            if (d[j] > d[head] + wi) {
                d[j] = d[head] + wi;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }

    }
    int dis = d[n];
    if (dis >= MAX / 2) {
        cout << "impossible";
    } else {
        cout << dis;
    }
}