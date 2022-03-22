#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;
int n, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> x;
        if (max_pq.size() == min_pq.size()) {
            max_pq.push(x);
        }
        else {
            min_pq.push(x);
        }
        if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top()) {
            int mx = max_pq.top();
            int mn = min_pq.top();
            max_pq.pop();
            min_pq.pop();
            max_pq.push(mn);
            min_pq.push(mx);
        }
        cout << max_pq.top()<<"\n";
    }
}
