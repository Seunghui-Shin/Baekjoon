#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
#define max_n 500000
int arr[max_n];

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
        cout << binary_search(arr, arr + n, k) << " ";
    }
}
