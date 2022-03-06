#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<bool> vec(1000001, true);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vec[1] = false;
    for (int i = 2;i * i <= m;i++) {
        if (!vec[i]) {
            continue;
        }
        for (int j = i * i;j <= m;j += i) {
            vec[j] = false;
        }
    }
    for (int i = n;i <= m;i++) {
        if (vec[i]) {
            cout << i << "\n";
        }
    }
}
