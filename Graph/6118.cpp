#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define max_n 20001
vector<int> graph[max_n];
int vis[max_n];
int n, m, u, v, dis, cnt = 0;
queue<int> q;

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
        vis[i] = -1;
    }
    q.push(1);
    vis[1] = 0;
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
    dis = *max_element(vis + 1, vis + n + 1);
    for (int i = 1;i <= n;i++) {
        if (dis == vis[i]) {
            cnt++;
        }
    }
    for (int i = 1;i <= n;i++) {
        if (dis == vis[i]) {
            cout << i << " " << dis << " " << cnt;
            return 0;
        }
    }
}
