#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 100000
int n;
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int max_weight = 0;
    for (int i = 1;i <= n;i++) {
        max_weight = max(max_weight, arr[n - i] * i);
    }
    cout << max_weight;
}
