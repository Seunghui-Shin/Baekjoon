#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define max_e 100001
tuple<int, int, int> edge[max_e];
#define max_n 10001
vector<int> p(max_n, -1);
int n, e, cost, u, v;

int find(int x) {
    if (p[x] < 0) {
        return x;
    }
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return 0;
    }
    if (p[u] == p[v]) {
        p[u]--;
    }
    if (p[u] < p[v]) {
        p[v] = u;
    }
    else {
        p[u] = v;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> e;
    for (int i = 0;i < e;i++) {
        cin >> u >> v >> cost;
        edge[i] = { cost,u,v };
    }
    sort(edge, edge + e);
    int cnt = 0;
    int res = 0;
    for (int i = 0;i < e;i++) {
        tie(cost, u, v) = edge[i];
        if (!is_diff_group(u, v)) {
            continue;
        }
        cnt++;
        res += cost;
        if (cnt == n - 1) {
            break;
        }
    }
    cout << res;
}
