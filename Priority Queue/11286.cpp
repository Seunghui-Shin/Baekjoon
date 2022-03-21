#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int n, x;

class compare {
public:
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, compare> pq;
    while (n--) {
        cin >> x;
        if (x != 0) {
            pq.push(x);
        }
        else {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}
