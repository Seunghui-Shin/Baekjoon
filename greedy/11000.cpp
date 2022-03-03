#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n;
#define max_n 200000
vector<pair<int, int>> vec;
long long start, finish;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> start >> finish;
        vec.push_back({ start,1 });
        vec.push_back({ finish,-1 });
    }
    sort(vec.begin(), vec.end());
    int res = 0;
    int cur = 0;
    int idx = 0;
    int curtime = vec[0].first;
    while (true) {
        while (idx < 2 * n && vec[idx].first == curtime) {
            cur += vec[idx].second;
            idx++;
        }
        res = max(res, cur);
        if (idx == 2 * n) {
            break;
        }
        curtime = vec[idx].first;
    }
    cout << res;
}
