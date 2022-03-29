#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define max_n 32001
vector<int> graph[max_n];
int deg[max_n];
queue<int> q;
vector<int> res;
int n, m, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        graph[u].push_back(v);
        deg[v]++;
    }
    for (int i = 1;i <= n;i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (auto nxt : graph[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << " ";
    }
}
