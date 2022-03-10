#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int n, height;
stack<pair<int, int>> st;

int main() {
    cin >> n;
    long long count = 0;
    for (int i = 0;i < n;i++) {
        cin >> height;
        while (!st.empty() && st.top().first < height) {
            count += st.top().second;
            st.pop();
        }
        if (st.empty()) {
            st.push({ height,1 });
        }
        else {
            if (st.top().first == height) {
                pair<int, int> temp = st.top();
                st.pop();
                count += temp.second;
                if (!st.empty()) {
                    count++;
                }
                temp.second++;
                st.push(temp);
            }
            else {
                st.push({ height,1 });
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
