#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, t;
int ans = 0;
vector<int> N;
vector<int> P;

void sum(vector<int> vec) {
    while (1 < vec.size()) {
        ans += *(vec.end() - 1) * *(vec.end() - 2);
        vec.pop_back();
        vec.pop_back();
    }
    if (vec.size()) {
        ans += vec[0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> t;
        if (t == 1) {
            ans++;
        }
        else if (t > 0) {
            P.push_back(t);
        }
        else {
            N.push_back(t);
        }
    }
    sort(P.begin(), P.end());
    sort(N.begin(), N.end(), greater<>());
    sum(P);
    sum(N);
    cout << ans;
}
