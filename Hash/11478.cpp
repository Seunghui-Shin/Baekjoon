#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<string> set;
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    for (int i = 0;i < str.length();i++) {
        for (int j = 1;i + j <= str.length();j++) {
            set.insert(str.substr(i, j));
        }
    }
    cout << set.size();
}
