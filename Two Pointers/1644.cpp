#include <iostream>
#include <vector>
using namespace std;
#define max_n 4000001
vector<bool> vec(max_n, true);
vector<int> tmp;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vec[1] = false;
    for (int i = 2;i * i <= n;i++) {
        if (!vec[i]) {
            continue;
        }
        for (int j = i * i;j <= n;j += i) {
            vec[j] = false;
        }
    }
    for (int i = 2;i <= n;i++) {
        if (vec[i]) {
            tmp.push_back(i);
        }
    }

    int start = 0, end = 0,cnt = 0;
    long long sum = 0;
    while (start < tmp.size() && end < tmp.size()) {
        sum += tmp[end];
        while (sum >= n) {
            if (sum == n) {
                cnt++;
            }
            sum -= tmp[start];
            start++;
        }
        end++;
    }
    cout << cnt;
}
