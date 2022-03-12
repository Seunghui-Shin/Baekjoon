#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 500000
int arr[max_n];
int n, m, k;

int lower_index(int k) {
    int start = 0, end = n;
    while (start < end) {
        int mid = (start + end) / 2;
        if (k <= arr[mid]) {
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }
    return start;
}

int upper_index(int k) {
    int start = 0, end = n;
    while (start < end) {
        int mid = (start + end) / 2;
        if (k >= arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return start;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> m;
    while (m--) {
        cin >> k;
        int lower = lower_index(k);
        int upper = upper_index(k);
        cout << upper - lower << "\n";
    }
}
