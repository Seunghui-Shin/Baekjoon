#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int n, m;
#define max_n 100000
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int start = 0, end = 0, res = INT_MAX;
    while (start < n && end < n) {
        if (arr[end] - arr[start] >= m) {
            res = min(res, arr[end] - arr[start]);
            start++;
        }
        else {
            end++;
        }
    }
    cout << res;
}
