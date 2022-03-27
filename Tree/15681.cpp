#include <iostream>
#include <vector>
using namespace std;
#define max_n 100001
vector<int> tree[max_n];
bool vis[max_n];
int res[max_n];
int n, r, q, query, u, v;

int dfs(int cur) {
    if (res[cur] != 0) {
        return res[cur];
    }
    vis[cur] = true;
    int cnt = 1;
    for (int i = 0;i < tree[cur].size();i++) {
        int nxt = tree[cur][i];
        if (vis[nxt]) {
            continue;
        }
        cnt += dfs(nxt);
    }
    res[cur] = cnt;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> q;
    for (int i = 0;i < n - 1;i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    res[r] = dfs(r);
    for (int i = 0;i < q;i++) {
        cin >> query;
        cout << res[query] << "\n";
    }
}
