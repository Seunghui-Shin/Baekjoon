#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n,dl,c;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> dl >> c;
        vec.push_back({ dl,c });
    }
    sort(vec.begin(), vec.end());
    for (int i = 0;i < n;i++) {
        if (pq.size() < vec[i].first) {
            pq.push(vec[i].second);
        }
        else {
            if (pq.top() < vec[i].second) {
                pq.pop();
                pq.push(vec[i].second);
            }
        }
    }
    long long max_cup = 0;
    while (!pq.empty()) {
        max_cup += pq.top();
        pq.pop();
    }
    cout << max_cup;
}
