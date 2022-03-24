#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define max_n 501
vector<int> graph[max_n];
queue<int> q;
int vis[max_n];
int n, m, u, v, cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        vis[i] = -1;
    }
    while (m--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : graph[cur]) {
            if (vis[nxt]!=-1 || vis[cur]>2) {
                continue;
            }
            q.push(nxt);
            cnt++;
            vis[nxt] = vis[cur] + 1;
        }
    }
    cout << cnt;
}
