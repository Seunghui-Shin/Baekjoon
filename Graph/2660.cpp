#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, u, v, cnt = 0;
#define max_n 51
vector<int> graph[max_n];
vector<int> vec;
int res[max_n];
int vis[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (true) {
        cin >> u >> v;
        if (u == -1 && v == -1) {
            break;
        }
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            vis[j] = -1;
        }
        queue<int> q;
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
        res[i] = *max_element(vis+1, vis + n+1);
    }
    int score = *min_element(res+1, res + n+1);
    for (int i = 1;i <= n;i++) {
        if (res[i] == score) {
            cnt++;
            vec.push_back(i);
        }
    }
    cout << score << " " << cnt << "\n";
    for (auto i : vec) {
        cout << i << " ";
    }
}
