#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> st;
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
            st.push(k);
        }
        else if (str == "pop") {
            if (st.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (str == "top") {
            if (st.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << st.top() << "\n";
            }
        }
        else if (str == "empty") {
            if (st.empty()) {
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
        else {
            cout << st.size() << "\n";
        }
    }
}
