#include <iostream>
#include <climits>
using namespace std;
int k, n;
#define max_k 10000
int arr[max_k];

bool solve(long long mid) {
    long long line = 0;
    for (int i = 0;i < k;i++) {
        line += arr[i] / mid;
    }
    return line >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for (int i = 0;i < k;i++) {
        cin >> arr[i];
    }
    long long start = 1;
    long long end = INT_MAX;
    while (start < end) {
        long long mid = (start + end + 1) / 2;
        if (solve(mid)) {
            start = mid;
        }
        else {
            end = mid - 1;
        }
    }
    cout << start;
}
