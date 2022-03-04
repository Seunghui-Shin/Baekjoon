#include <iostream>
using namespace std;
int n, v, x;
#define max_n 201
int arr[max_n];

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> v;
        arr[v + 100]++;
    }
    cin >> x;
    int ans=0;
    for (int i = 0;i < max_n;i++) {
        if (i == x + 100) {
            ans = arr[i];
        }
    }
    cout << ans;
    return 0;
}
