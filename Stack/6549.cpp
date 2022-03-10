#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define max_n 100001
int arr[max_n];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        cin >> n;
        if (!n) {
            break;
        }
        for (int i = 0;i < n;i++) {
            cin >> arr[i];
        }
        arr[n] = -1;
        stack<int> st;
        long long ans = 0;
        for (int i = 0;i <= n;i++) {
            while (st.size() && arr[i] < arr[st.top()]) {
                int pos = st.top();
                st.pop();
                long long len = (st.empty() ? i : i - st.top() - 1);
                ans = max(ans, arr[pos] * len);
            }
            st.push(i);
        }
        cout << ans << "\n";
    }
}
