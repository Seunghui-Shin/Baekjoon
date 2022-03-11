#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<int> q;
int n, k;
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> str;
        if (str == "push") {
            cin >> k;
            q.push(k);
        }
        else if (str == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (str == "size") {
            cout << q.size() << "\n";
        }
        else if (str == "empty") {
            cout << q.empty() << "\n";
        }
        else if (str == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        else {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
}
