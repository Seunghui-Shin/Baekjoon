#include <iostream>
#include <stack>
using namespace std;
int n, k;
stack<int> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> k;
        if (k == 0) {
            st.pop();
        }
        else {
            st.push(k);
        }
    }
    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}
