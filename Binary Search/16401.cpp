#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int m, n;
#define max_n 1000000
int arr[max_n];

long long solve(long long mid) {
    long long line = 0;
    for (int i = 0;i < n;i++) {
        line += arr[i] / mid;
    }
    return line >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    long long start = 1, end = INT_MAX;
    bool check = false;
    while (start < end) {
        long long mid = (start + end + 1) / 2;
        if (solve(mid)) {
            start = mid;
            check = true;
        }
        else {
            end = mid - 1;
        }
    }
    if(check){
        cout << start;
    }
    else {
        cout << 0;
    }
}
