#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define max_n 100001
vector<int> tree[max_n];
queue<int> q;
int p[max_n];
int n, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n - 1;i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : tree[cur]) {
            if (p[cur] == nxt) {
                continue;
            }
            q.push(nxt);
            p[nxt] = cur;
        }
    }
    for (int i = 2;i < n + 1;i++) {
        cout << p[i] << "\n";
    }
}
