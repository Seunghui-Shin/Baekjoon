#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define max_n 1001
vector<int> graph[max_n];
vector<string> child[max_n];
vector<string> parent;
vector<string> person;
queue<int> q;
map<string, int> om;
map<int, string> rm;
int deg[max_n];
int n, m;
string u, v, per;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> per;
        person.push_back(per);
    }
    sort(person.begin(), person.end());

    for (int i = 0;i < person.size();i++) {
        om[person[i]] = i + 1;
        rm[i + 1] = person[i];
    }

    cin >> m;
    while (m--) {
        cin >> u >> v;
        graph[om[v]].push_back(om[u]);
        deg[om[u]]++;
    }

    for (int i = 1;i <= n;i++) {
        if (deg[i] == 0) {
            parent.push_back(rm[i]);
            q.push(i);
        }
    }
    cout << parent.size() << "\n";
    sort(parent.begin(), parent.end());
    for (auto i : parent) {
        cout << i << " ";
    }
    cout << "\n";

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : graph[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) {
                child[cur].push_back(rm[nxt]);
                q.push(nxt);
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        sort(child[i].begin(), child[i].end());
    }

    for (int i = 1;i <= n;i++) {
        cout << rm[i] << " " << child[i].size() << " ";
        for (int j = 0;j < child[i].size();j++) {
            cout << child[i][j] << " ";
        }
        cout << "\n";
    }
}
