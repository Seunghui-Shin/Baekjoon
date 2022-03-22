#include <iostream>
#include <queue>
using namespace std;
int t, k, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        cin >> k;
        for (int i = 0;i < k;i++) {
            cin >> x;
            pq.push(x);
        }
        long long cnt = 0;
        while (pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            cnt += a + b;
            pq.push(a + b);
        }
        cout << cnt << "\n";
    }
}
