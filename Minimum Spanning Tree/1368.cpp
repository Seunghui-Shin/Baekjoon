#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;
#define max_n 302
vector<pair<int, int>> edge[max_n];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
bool check[max_n];
int n, cost, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> cost;
        edge[i].push_back({ cost,n + 1 });
        edge[n + 1].push_back({ cost,i });
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> cost;
            if (cost != 0) {
                edge[i].push_back({ cost,j });
            }
        }
    }
    check[1] = 1;
    for (auto nxt : edge[1]) {
        pq.push({ nxt.first,1,nxt.second });
    }
    int cnt = 0;
    int res = 0;
    while (cnt < n) {
        tie(cost, u, v) = pq.top();
        pq.pop();
        if (check[v]) {
            continue;
        }
        res += cost;
        cnt++;
        check[v] = true;
        for (auto nxt : edge[v]) {
            if (!check[nxt.second]) {
                pq.push({ nxt.first,v,nxt.second });
            }
        }
    }
    cout << res;
}
