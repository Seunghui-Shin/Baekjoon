#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, k,max_k=0;
stack<int> st;
vector<char> v;
bool check = false;
int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> k;
        if (max_k < k) {
            for (int j = max_k + 1;j <= k;j++) {
                st.push(j);
                v.push_back('+');
            }
            max_k = k;
        }
        else {
            if (k != st.top()) {
                check = true;
            }
        }
        st.pop();
        v.push_back('-');
    }
    if (check) {
        cout << "NO";
    }
    else {
        for (int i = 0;i < v.size();i++) {
            cout << v[i] << "\n";
        }
    }
    return 0;
}
