#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define max_n 1001
vector<int> graph[max_n];
int deg[max_n];
#define max_m 100
int tmp[max_m];
vector<int> res;
queue<int> q;
int n, m, pd, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        cin >> pd;
        for (int i = 0;i < pd;i++) {
            cin >> tmp[i];
        }
        for (int i = 0;i < pd - 1;i++) {
            graph[tmp[i]].push_back(tmp[i + 1]);
            deg[tmp[i + 1]]++;
        }
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
    if (res.size() != n) {
        cout << 0 << "\n";
    }
    else {
        for (int i = 0;i < res.size();i++) {
            cout << res[i] << "\n";
        }
    }
}
