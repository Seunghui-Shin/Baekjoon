#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int n, height;
stack<pair<int,int>> st;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    st.push({ 100000001,0 });
    for (int i = 1;i <= n;i++) {
        cin >> height;
        while (st.top().first < height) {
            st.pop();
        }
        cout << st.top().second << " ";
        st.push({ height,i });
    }
    return 0;
}
