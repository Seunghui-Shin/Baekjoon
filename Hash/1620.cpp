#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
#define max_n 100001
string arr[max_n];
unordered_map<string, int> book;
string poketmon, str;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        book[arr[i]] = i;
    }
    while (m--) {
        cin >> str;
        if (isdigit(str[0])) {
            cout << arr[stoi(str)] << "\n";
        }
        else {
            cout << book[str] << "\n";
        }
    }
}
