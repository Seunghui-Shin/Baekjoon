#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, string> map;
int n, m;
string address, num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> address >> num;
        map[address] = num;
    }
    while (m--) {
        cin >> address;
        cout << map[address] << "\n";
    }
}
