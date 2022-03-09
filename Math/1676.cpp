#include <iostream>
using namespace std;
int n;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n) {
        cnt += n / 5;
        n /= 5;
    }
    cout << cnt;
}
