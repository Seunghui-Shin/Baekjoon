#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define max_n 10001
vector<bool> vec(max_n, true);
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vec[1] = false;
    for (int i = 2;i * i < max_n;i++) {
        if (!vec[i]) {
            continue;
        }
        for (int j = i * i;j < max_n;j += i) {
            vec[j] = false;
        }
    }

    cin >> t;
    while (t--) {
        cin >> n;
        int res = INT_MAX;
        int part1=0, part2=0;
        for (int i = 2;i * 2 <= n;i++) {
            if (vec[i]) {
                int part = n - i;
                if (vec[part]) {
                    if (part - i < res) {
                        res = part - i;
                        part1 = i;
                        part2 = part;
                    }
                }
            }
        }
        cout << part1 << " " << part2 << "\n";
    }
}
