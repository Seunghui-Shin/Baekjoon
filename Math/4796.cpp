#include <iostream>
#include <algorithm>
using namespace std;
int l, p, v;
int cs = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) {
            return 0;
        }
        cout << "Case " << cs++ << ": " << v / p * l + min(l, v % p) << "\n";
    }
}
