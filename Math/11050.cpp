#include <iostream>
using namespace std;
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int res = 1;
    for (int i = 2;i <= n;i++) {
        res *= i;
    }
    for (int i = 2;i <= k;i++) {
        res /= i;
    }
    for (int i = 2;i <= n - k;i++) {
        res /= i;
    }
    cout << res;
}
