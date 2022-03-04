#include <iostream>
#include <string>
using namespace std;
int a, b, c;
int mult;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    mult = a * b * c;
    string str = to_string(mult);
    for (char i = '0';i <= '9';i++) {
        int count = 0;
        for (int j =0 ;j < str.length();j++) {
            if (i == str[j]) {
                count++;
            }
        }
        cout << count << "\n";
    }
}
