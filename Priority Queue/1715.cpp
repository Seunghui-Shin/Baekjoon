#include <iostream>
#include <queue>
using namespace std;
int n, x;
priority_queue<int, vector<int>, greater<int>> pq;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> x;
        pq.push(x);
    }
    while (pq.size()>1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cnt += a + b;
        pq.push(a+b);
    }
    cout<<cnt;
}
