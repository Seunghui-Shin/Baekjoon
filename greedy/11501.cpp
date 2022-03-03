#include <iostream>
using namespace std;
int t, n;
#define max_n 1000000

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[max_n];
        for (int i = 0;i < n;i++) {
            cin >> arr[i];
        }
        long long res = 0;
        int max_val = arr[n - 1];
        for (int i = n - 2;i >= 0;i--) {
            if (max_val < arr[i]) {
                max_val = arr[i];
            }
            res += max_val - arr[i];
        }
        cout << res << "\n";
    }
}
