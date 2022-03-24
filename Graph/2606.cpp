#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define max_n 101
vector<int> graph[max_n];
queue<int> q;
bool vis[max_n];
int n, m, u, v, cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> m;
    while (m--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : graph[cur]) {
            if (vis[nxt]) {
                continue;
            }
            q.push(nxt);
            cnt++;
            vis[nxt] = true;
        }
    }
    cout << cnt;
}
