#include <iostream>
#include <string>
using namespace std;
string str;
int tmp = 0, res = 0, sign = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    for (int i = 0;i < str.length();i++) {
        if (str[i] == '+' || str[i] == '-') {
            res += tmp * sign;
            if (str[i] == '-') {
                sign = -1;
            }
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += str[i] - '0';
        }
    }
    res += tmp * sign;
    cout << res;
}
