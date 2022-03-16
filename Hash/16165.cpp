#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, num;
string group, member, problem;
unordered_map<string, string> girl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (n--) {
        cin >> group;
        cin >> num;
        for (int i = 0;i < num;i++) {
            cin >> member;
            girl[member] = group;
        }
    }
    while (m--) {
        cin >> problem;
        cin >> num;
        vector<string> vec;
        if (num == 0) {
            for (auto i : girl) {
                if (i.second == problem) {
                    vec.push_back(i.first);
                }
            }
            sort(vec.begin(), vec.end());
            for (auto i : vec) {
                cout << i << "\n";
            }
        }
        else {
            cout << girl[problem] << "\n";
        }
    }
}
