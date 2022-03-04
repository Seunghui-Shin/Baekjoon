#include <iostream>
#include <algorithm>
using namespace std;
int n, x;
#define max_n 100000
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + n);
    int count = 0;
    int first = 0, last = n - 1;
    while (first < last) {
        if (arr[first] + arr[last] == x) {
            count++;
            first++;
            last--;
        }
        else if (arr[first] + arr[last] < x) {
            first++;
        }
        else {
            last--;
        }
    }
    cout << count;
}
