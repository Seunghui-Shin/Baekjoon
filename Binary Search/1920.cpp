#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
#define max_n 100000
int arr[max_n];

int binarysearch(int k) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (k < arr[mid]) {
            end = mid - 1;
        }
        else if (k > arr[mid]) {
            start = mid + 1;
        }
        else {
            return 1;
        }
    }
    return 0;
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
        cout << binarysearch(k) << "\n";
    }
}
