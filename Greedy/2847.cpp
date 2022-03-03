#include <iostream>
using namespace std;
int n;
#define max_n 100
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    int last = arr[n - 1];
    long long res = 0;
    for (int i = n - 2;i >= 0;i--) {
        if (arr[i] >= last) {
            last--;
            res += arr[i] - last;
            
        }
        else {
            last = arr[i];
        }
    }
    cout << res;
}
