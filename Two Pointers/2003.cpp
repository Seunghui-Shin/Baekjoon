#include <iostream>
using namespace std;
int n, m;
#define max_n 10000
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    int start = 0, end = 0, cnt = 0, sum = 0;
    while (start < n && end < n) {
        sum += arr[end];
        while (sum >= m) {
            if (sum == m) {
                cnt++;
            }
            sum -= arr[start];
            start++;
        }
        end++;
    }
    cout << cnt;
}
