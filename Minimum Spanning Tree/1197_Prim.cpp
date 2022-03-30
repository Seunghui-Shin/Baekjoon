#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
#define max_n 10001
using namespace std;
vector<pair<int,int>> edge[max_n];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
bool check[max_n];
int n, e, u, v, cost;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> e;
    for (int i = 0;i < e;i++) {
        cin >> u >> v >> cost;
        edge[u].push_back({ cost, v });
        edge[v].push_back({ cost, u });
    }
    check[1] = 1;
    for (auto nxt : edge[1]) {
        pq.push({ nxt.first,1,nxt.second });
    }
    int cnt = 0;
    int res = 0;
    while (cnt < n - 1) {
        tie(cost, u, v) = pq.top();
        pq.pop();
        if (check[v]) {
            continue;
        }
        res += cost;
        check[v]=1;
        cnt++;
        for (auto nxt : edge[v]) {
            if (!check[nxt.second]) {
                pq.push({ nxt.first, v, nxt.second });
            }
        }
    }
    cout << res;
}
