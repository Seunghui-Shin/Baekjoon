#include <iostream>
using namespace std;
#define max_n 101
int n;
bool graph[max_n][max_n];
bool vis[max_n];

void dfs(int cur) {
    for (int k = 1;k <= n;k++) {
        if (graph[cur][k] == 1 && !vis[k]) {
            vis[k] = true;
            dfs(k);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            vis[j] = 0;
        }
        dfs(i);
        for (int j = 1;j <= n;j++) {
            if (vis[j]) {
                graph[i][j] = 1;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}
