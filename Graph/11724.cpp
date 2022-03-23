#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define max_n 1001
vector<int> graph[max_n];
bool vis[max_n];
int n, m, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        if (vis[i]) {
            continue;
        }
        cnt++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : graph[cur]) {
                if (vis[nxt]) {
                    continue;
                }
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << cnt;
}
