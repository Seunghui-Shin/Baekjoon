#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str;
int cnt = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    for (int i = 0;i < str.length();i++) {
        for (int j = i+1;j < str.length();j++) {
            if (str[i] != str[j]) {
                cnt++;
                i = j - 1;
                break;
            }
        }
    }
    if (cnt == 0) {
        cout << 0;
    }
    else if (cnt % 2 == 0) {
        cout << cnt / 2;
    }
    else {
        cout << cnt/2+1;
    }
}
