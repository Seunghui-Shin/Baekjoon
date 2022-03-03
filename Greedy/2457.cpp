#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int m1, d1, m2, d2;
vector<pair<int, int>> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> m1 >> d1 >> m2 >> d2;
        vec.push_back({ m1 * 100 + d1,m2 * 100 + d2 });
    }
    int t = 301;
    int cnt = 0;
    while (t < 1201) {
        int nxt_t = t;
        for (int i = 0;i < n;i++) {
            if (vec[i].first <= t && vec[i].second > nxt_t) {
                nxt_t = vec[i].second;
            }
        }
        if (nxt_t == t) {
            cout << 0;
            return 0;
        }
        cnt++;
        t = nxt_t;
    }
    cout << cnt;
}
