#include <iostream>
using namespace std;
int t, m, n, x, y;

int gcd(int m, int n) {
    if (m == 0) {
        return n;
    }
    return gcd(n % m, m);
}

int lcm(int m, int n) {
    return m / gcd(m, n) * n;
}

int solve(int m, int n, int x, int y) {
    if (m == x) {
        x = 0;
    }
    if (n == y) {
        y = 0;
    }
    int last = lcm(m, n);
    for (int i = x;i <= last;i+=m) {
        if(i==0){
            continue;
        }
        if (i % n == y) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;
        cout << solve(m, n, x, y) << "\n";
    }
}
