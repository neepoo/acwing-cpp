#include <iostream>
#include <vector>
#include <stack>

const int N = 100010;
int h[N], e[2*N], ne[2*N], idx;
std::vector<int> state(N, 0); // 0=未访问，1=正在访问，2=已访问
std::stack<int> st; // 用栈存储拓扑排序的结果
bool has_cycle = false;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    state[u] = 1; // 标记为正在访问
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (state[j] == 0) {
            dfs(j);
            if (has_cycle) return; // 如果发现环，则退出
        } else if (state[j] == 1) {
            // 如果遇到正在访问的节点，则表示图中存在环
            has_cycle = true;
            return;
        }
    }
    state[u] = 2; // 标记为已访问
    st.push(u); // 将节点加入到栈中
}

int main() {
    std::fill(h, h + N, -1);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
    }

    for (int i = 1; i <= n; ++i) {
        if (state[i] == 0) {
            dfs(i);
            if (has_cycle) {
                std::cout << "-1\n";
                return 0; // 如果发现环，则不存在拓扑排序
            }
        }
    }

    // 如果没有环，则输出拓扑排序的结果
    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << "\n";

    return 0;
}
