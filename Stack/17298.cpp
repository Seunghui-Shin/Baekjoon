#include <iostream>
#include <stack>
using namespace std;
#define max_n 1000000
int n;
stack<int> st;
int arr[max_n];
int ans[max_n];

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    for (int i = n - 1;i > -1;i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    for (int i = 0;i < n;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
