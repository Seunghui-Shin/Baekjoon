#include <iostream>
#include <vector>
using namespace std;
vector<bool> vec(1001, true);
int n, k;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vec[1] = false;
    cin >> n >> k;
    for (int i = 2;i <= n;i++) {
        if (vec[i]) {
            vec[i] = false;
            cnt++;
        }
        if (cnt == k) {
            cout<< i;
            return 0;
        }
        for (int j = i * i;j <= n;j += i) {
            if (vec[j]) {
                vec[j] = false;
                cnt++;
                if (cnt == k) {
                    cout << j;
                    return 0;
                }
            }
        }
    }
}
