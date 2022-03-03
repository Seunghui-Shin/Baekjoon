#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 1000
int arr[max_n];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int res = 0;
    int sum = 0;
    for (int i = 0;i < n;i++) {
        sum += arr[i];
        res += sum;
    }
    cout << res;
}
