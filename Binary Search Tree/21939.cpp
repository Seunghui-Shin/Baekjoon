#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
using namespace std;
int n, p, l, m, x;
string str;
map<int, int> mp;
multiset<pair<int,int>> ms;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> p >> l;
        mp[p] = l;
        ms.insert({ l,p });
    }
    cin >> m;
    while (m--) {
        cin >> str;
        if (str == "add") {
            cin >> p >> l;
            mp[p] = l;
            ms.insert({ l,p });
        }
        else if (str == "recommend") {
            cin >> x;
            if (x == 1) {
                auto it = prev(ms.end());
                cout << it->second << "\n";
            }
            else {
                auto it = ms.begin();
                cout << it->second << "\n";
            }
        }
        else {
            cin >> p;
            int hard = mp[p];
            auto it = ms.find({ hard,p });
            ms.erase(it);
            mp.erase(p);
        }
    }
}
