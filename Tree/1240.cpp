#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define max_n 1001
vector<pair<int, int>> tree[max_n];
int vis[max_n];
int m, n, u, v, d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n - 1;i++) {
        cin >> u >> v >> d;
        tree[u].push_back({ v,d });
        tree[v].push_back({ u,d });
    }
    while (m--) {
        cin >> u >> v;
        queue<int> q;
        for (int i = 1;i <= n;i++) {
            vis[i] = -1;
        }
        q.push(u);
        vis[u] = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto nxt : tree[cur]) {
                if (vis[nxt.first] >= 0) {
                    continue;
                }
                vis[nxt.first] = vis[cur] + nxt.second;
                q.push(nxt.first);
            }
        }
        cout << vis[v] << "\n";
    }
}
