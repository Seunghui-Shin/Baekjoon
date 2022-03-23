#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, start, u, v;
#define max_n 1001
vector<int> graph[max_n];
bool visdfs[max_n];
bool visbfs[max_n];
queue<int> q;

void DFS(int cur) {
    visdfs[cur] = true;
    cout << cur << " ";
    for (auto nxt : graph[cur]) {
        if (visdfs[nxt]) {
            continue;
        }
        DFS(nxt);
    }
}

void BFS(int cur) {
    q.push(cur);
    visbfs[cur] = true;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur << " ";
        for (auto nxt : graph[cur]) {
            if (visbfs[nxt]) {
                continue;
            }
            q.push(nxt);
            visbfs[nxt] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> start;
    for (int i = 0;i < m;i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    DFS(start);
    cout<<"\n";
    BFS(start);
}
