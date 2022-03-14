#include <iostream>
#include <climits>
using namespace std;
int n, s;
#define max_n 100000
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    int start = 0, end = 0, res = INT_MAX, sum = 0;
    while (start < n && end < n) {
        sum += arr[end];
        while (sum >= s) {
            int cnt = end - start+1;
            res = min(res, cnt);
            sum -= arr[start];
            start++;
        }
        end++;
    }
    if (res == INT_MAX) {
        cout << 0;
    }
    else {
        cout << res;
    }
}
