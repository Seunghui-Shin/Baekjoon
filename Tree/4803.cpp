#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define max_n 501
int n, m, u, v, t = 1;
bool vis[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            return 0;
        }
        vector<int> tree[max_n];
        while (m--) {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        for (int i = 1;i <= n;i++) {
            vis[i] = 0;
        }
        int cnt = 0;
        for (int i = 1;i <= n;i++) {
            queue<pair<int,int>> q;
            if (vis[i]) {
                continue;
            }
            q.push({ i,0 });
            vis[i] = true;
            bool check = false;
            while (!q.empty()) {
                int cur = q.front().first;
                int p = q.front().second;
                q.pop();
                for (auto nxt : tree[cur]) {
                    if (nxt != p) {
                        if (vis[nxt]) {
                            check = true;
                            break;
                        }
                        else {
                            q.push({ nxt,cur });
                            vis[nxt] = true;
                        }
                    }
                }
                if (check) {
                    break;
                }
            }
            if (!check) {
                cnt++;
            }
        }
        if (cnt == 0) {
            cout << "Case " << t++ << ": No trees." << "\n";
        }
        else if (cnt == 1) {
            cout << "Case " << t++ << ": There is one tree." << "\n";
        }
        else {
            cout << "Case " << t++ << ": A forest of " << cnt << " trees." << "\n";
        }
    }
}
