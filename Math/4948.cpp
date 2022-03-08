#include <iostream>
#include <vector>
using namespace std;
int n;
#define max_n 123456*2+1
vector<bool> vec(max_n, true);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vec[1] = false;
    for (int i = 2;i * i <= max_n;i++) {
        if (!vec[i]) {
            continue;
        }
        for (int j = i * i;j <= max_n;j += i) {
            vec[j] = false;
        }
    }

    while (true) {
        cin >> n;
        if (n == 0) {
            return 0;
        }
        int cnt = 0;
        for (int i = n + 1;i <= 2 * n;i++) {
            if (vec[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
