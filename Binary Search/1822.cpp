#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k;
vector<int> a;
vector<int> b;
vector<int> res;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> k;
        a.push_back(k);
    }
    sort(a.begin(), a.end());
    for (int i = 0;i < m;i++) {
        cin >> k;
        b.push_back(k);
    }
    sort(b.begin(), b.end());
    for (int i = 0;i < n;i++) {
        if (!binary_search(b.begin(), b.end(), a[i])) {
            res.push_back(a[i]);
            cnt++;
        }
    }
    if (res.empty()) {
        cout << 0;
    }
    else {
        cout << cnt << "\n";
        for (int i = 0;i < res.size();i++) {
            cout << res[i] << " ";
        }
    }
}
