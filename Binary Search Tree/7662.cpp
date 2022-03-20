#include <iostream>
#include <set>
using namespace std;
int t, k, n;
char c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> k;
        multiset<int> ms;
        for (int i = 0;i < k;i++) {
            cin >> c >> n;
            if (c == 'I') {
                ms.insert(n);
            }
            else {
                if (ms.size() == 0) {
                    continue;
                }
                if (n == -1) {
                    ms.erase(ms.begin());
                }
                else {
                    ms.erase(prev(ms.end()));
                }
            }
        }
        if (ms.size() == 0) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
        }
    }
}
