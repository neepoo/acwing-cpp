#include<iostream>
#include<algorithm> // 需要包含此头文件以使用 std::fill 和 std::max

const int N = 100010;

int h[N], e[2*N], ne[2*N], idx, n, ans = 0x3f3f3f3f;
bool visited[N]; // 使用更清晰的命名

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 返回以u为root的子树的节点数量。
int dfs(int u) {
    visited[u] = true;
    int sum = 1;
    int maxPart = 0; // sum存储子树大小，maxPart存储最大的子树大小

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!visited[j]) {
            int subCnt = dfs(j);
            maxPart = std::max(maxPart, subCnt); // 找到最大的子树大小
            sum += subCnt;
        }
    }
    maxPart = std::max(maxPart, n - sum); // 比较分割后的另一部分
    ans = std::min(ans, maxPart); // 更新结果
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::fill(h, h + N, -1);
    std::fill(visited, visited + N, false); // 初始化visited数组
    std::cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1); // 假设1是根节点，并且树是连通的
    std::cout << ans;
}
