#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
#define max_n 10
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string str = to_string(n);

    for (char i = '0';i <= '9';i++) {
        for (int j = 0;j < str.length();j++) {
            if (i == str[j]) {
                arr[i - '0']++;
            }
        }
    }
    int sum;
    if (arr[6] + arr[9] == 0) {
        sum = 0;
    }
    else {
        sum = (arr[6] + arr[9]-1) / 2 + 1;
    }

    int count = 0;
    int max_count = 0;
    for (int i = 0;i < 10;i++) {
        if (i == 6 || i == 9) {
            count = sum;
        }
        else {
            count = arr[i];
        }
        max_count = max(max_count, count);
    }
    cout << max_count;
}
