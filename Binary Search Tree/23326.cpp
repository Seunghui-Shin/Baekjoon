#include <iostream>
#include <set>
using namespace std;
int n, query, a, q, place, go;
set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> query;
    for (int i = 1;i <= n;i++) {
        cin >> a;
        if (a == 1) {
            s.insert(i);
        }
    }
    int now = 1;
    while (query--) {
        cin >> q;
        if (q == 1) {
            cin >> place;
            if (s.count(place)){
                s.erase(place);
            }
            else {
                s.insert(place);
            }
        }
        else if (q == 2) {
            cin >> go;
            go %= n;
            now += go;
            if (now > n) {
                now %= n;
            }
        }
        else {
            if (s.empty()) {
                cout << -1 << "\n";
                continue;
            }
            auto it = s.lower_bound(now);
            if (it != s.end()) {
                cout << *it - now << "\n";
            }
            else {
                cout << *s.begin() - now + n << "\n";
            }
        }
    }
}
