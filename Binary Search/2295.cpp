#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
#define max_n 1000
int arr[max_n];
vector<int> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0;i < n;i++) {
        for (int j = i;j < n;j++) {
            vec.push_back(arr[i] + arr[j]);
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = n - 1;i >= 0;i--) {
        for (int j = 0;j < i;j++) {
            if (binary_search(vec.begin(), vec.end(), arr[i] - arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }
}
