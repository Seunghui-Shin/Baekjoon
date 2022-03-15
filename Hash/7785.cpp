#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
string name, record;
unordered_set<string> set;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> name >> record;
        if (record == "enter") {
            set.insert(name);
        }
        else {
            set.erase(name);
        }
    }
    vector<string> vec(set.begin(), set.end());
    sort(vec.begin(), vec.end(), greater<string>());
    for (auto i : vec) {
        cout << i << "\n";
    }
}
