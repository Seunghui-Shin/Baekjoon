#include <iostream>
using namespace std;
int t;
int n;
#define max_n 100

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        long long res = 0;
        int arr[max_n];
        cin >> n;
        for (int i = 0;i < n;i++) {
            cin >> arr[i];
        }
        for (int i = 0;i < n - 1;i++) {
            for (int j = i + 1;j < n;j++) {
                res += gcd(arr[i], arr[j]);
            }
        }
        cout << res << "\n";
    }
}
