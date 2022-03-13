#include <iostream>
#include <climits>
using namespace std;
int n, m;
#define max_n 1000000
long long tree[max_n];

long long solve(long long mid) {
    long long cut = 0;
    for (int i = 0;i < n;i++) {
        if (tree[i] > mid) {
            cut += (tree[i] - mid);
        }
    }
    return cut >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> tree[i];
    }
    long long start = 0, end = INT_MAX;
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
