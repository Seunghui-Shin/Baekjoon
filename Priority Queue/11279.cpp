#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int n, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
}
