#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define max_n 101
vector<int> graph[max_n];
int vis[max_n];
int res[max_n];
int n, m, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) {
        queue<int> q;
        for (int j = 1;j <= n;j++) {
            vis[j] = -1;
        }
        q.push(i);
        vis[i] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : graph[cur]) {
                if (vis[nxt] != -1) {
                    continue;
                }
                q.push(nxt);
                vis[nxt] = vis[cur] + 1;
            }
        }
        int bacon = 0;
        for (int j = 1;j <= n;j++) {
            bacon += vis[j];
        }
        res[i] = bacon;
    }
    int min_bacon = *min_element(res + 1, res + n + 1);
    for (int i = 1;i <= n;i++) {
        if (min_bacon == res[i]) {
            cout << i;
            return 0;
        }
    }
}
