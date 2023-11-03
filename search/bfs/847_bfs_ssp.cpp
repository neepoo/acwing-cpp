//
// Created by neepoo on 11/3/23.
//
#include<iostream>

const int N = 100010;
const int MAX = 0x3f3f3f3f;
int n, m;
int d[N];
int e[N], ne[N], h[N], idx;
int q[N], hh, tt;

void add(int a, int b ) {
    e[idx] =b;
    ne[idx] = h[a];
    h[a] = idx++;
}

using namespace std;

void bfs() {
    q[0] = 1;
    d[1]= 0;
    while(hh <= tt) {
        int head = q[hh++];
        for (int i = h[head];i!=-1;i=ne[i]){
            int j = e[i];
            if (d[j] == MAX){
                d[j] = d[head]+1;
                q[++tt] = j;
            }
        }
    }
    if (d[n] == MAX) d[n]=-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(d, d+N, MAX);
    fill(h, h+N, -1);
    cin>>n >> m;
    int a, b;
    while(m--){
        cin >> a >> b;
        add(a, b);
    }
    bfs();
    cout << d[n];
}