#include <iostream>
#include <vector>
using namespace std;
#define max_n 51
vector<int> tree[max_n];
int n, p, del, root;

int dfs(int cur) {
    int child = 0;
    int leaf = 1;
    for (auto nxt : tree[cur]) {
        if (nxt == del) {
            continue;
        }
        child += dfs(nxt);
    }
    if (child) {
        return child;
    }
    else {
        return leaf;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> p;
        if (p == -1) {
            root = i;
            continue;
        }
        tree[p].push_back(i);
    }
    cin >> del;
    if (del == root) {
        cout << 0;
    }
    else {
        cout << dfs(root);
    }
}
