#include <iostream>
#include <algorithm>
using namespace std;
int n;
#define max_n 100000
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int res1 = 1000000000, res2 = 1000000000;
    for (int i = 0;i < n;i++) {
        int idx = lower_bound(arr, arr + n, -arr[i]) - arr;
        if (idx + 1 < n && i != idx + 1 && abs(arr[i] + arr[idx + 1]) < abs(res1 + res2)) {
            res1 = arr[i];
            res2 = arr[idx + 1];
        }
        if (idx < n && i != idx && abs(arr[i] + arr[idx]) < abs(res1 + res2)) {
            res1 = arr[i];
            res2 = arr[idx];
        }
        if (idx != 0 && i != idx - 1 && abs(arr[i] + arr[idx - 1]) < abs(res1 + res2)) {
            res1 = arr[i];
            res2 = arr[idx - 1];
        }
    }
    if (res1 > res2) {
        swap(res1, res2);
    }
    cout << res1 << " " << res2;
}
