#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int t, n;
string name, kind;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        unordered_map<string, int> clothes;
        cin >> n;
        for (int i = 0;i < n;i++) {
            cin >> name >> kind;
            clothes[kind]++;
        }
        int ans = 1;
        for (auto i : clothes) {
            ans *= i.second + 1;
        }
        cout << ans - 1 << "\n";
    }
}
