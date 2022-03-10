#include <iostream>
#include <stack>
using namespace std;
int n, height;
stack<int> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long count = 0;
    for (int i = 0;i < n;i++) {
        cin >> height;
        while (!st.empty() && st.top() <= height) {
            st.pop();
        }
        count += st.size();
        st.push(height);
    }
    cout << count;
    return 0;
}
