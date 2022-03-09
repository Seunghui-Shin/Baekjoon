#include <iostream>
#include <algorithm>
using namespace std;
string str;
int sum = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    bool check = false;
    for (int i = 0;i < str.length();i++) {
        sum += str[i];
        if (str[i] == '0') {
            check = true;
        }
    }
    if (sum % 3 == 0 && check) {
        sort(str.begin(), str.end(),greater<>());
        cout << str;
    }
    else {
        cout << -1;
    }
}
