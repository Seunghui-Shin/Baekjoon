#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define max_n 10001
vector<int> graph[max_n];
bool vis[max_n];
int res[max_n];
int n, m, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        graph[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            vis[j] = false;
        }
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
        int cnt = 0;
        for (int j = 1;j <= n;j++) {
            if (vis[j]) {
                cnt++;
            }
        }
        res[i] = cnt;
    }
    int computer = *max_element(res + 1, res + n + 1);
    for (int i = 1;i <= n;i++) {
        if (res[i] == computer) {
            cout << i << " ";
        }
    }
}
