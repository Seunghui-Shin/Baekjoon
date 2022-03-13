#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, m;
long long cnt=0;
#define max_n 1001
long long a[max_n];
long long b[max_n];
long long dpa[max_n];
long long dpb[max_n];
vector<long long> veca;
vector<long long> vecb;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        dpa[i] = a[i] + dpa[i - 1];
    }
    cin >> m;
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
        dpb[i] = b[i] + dpb[i - 1];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            veca.push_back(dpa[i] - dpa[j]);
        }
    }
    for (int i = 1;i <= m;i++) {
        for (int j = 0;j < i;j++) {
            vecb.push_back(dpb[i] - dpb[j]);
        }
    }
    sort(veca.begin(), veca.end());
    sort(vecb.begin(), vecb.end());
    for (int i = 0;i < veca.size();i++) {
        long long val = t - veca[i];
        cnt += upper_bound(vecb.begin(), vecb.end(), val) - lower_bound(vecb.begin(), vecb.end(), val);
    }
    cout << cnt;
}
