#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 50
int a[max_n];
int b[max_n];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int ans = 0;
    for (int i = 0;i < n;i++) {
        ans += a[i] * b[n - i - 1];
    }
    cout << ans;
}
