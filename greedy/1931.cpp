#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define max_n 100000
pair<int, int> arr[max_n];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr + n);

    int cnt = 0;
    int t = 0;
    for (int i = 0;i < n;i++) {
        if (t > arr[i].second) {
            continue;
        }
        cnt++;
        t = arr[i].first;
    }
    cout << cnt;
}
