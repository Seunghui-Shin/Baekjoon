#include <iostream>
using namespace std;
#define max_n 1001
int arr[max_n][max_n];
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (int j = 1;j < i;j++) {
            arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
        }
    }
    cout << arr[n][k];
}
