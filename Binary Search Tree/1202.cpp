#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
int n, k, m, v, c;
#define max_n 1000000
pair<int, int> jewel[max_n];
multiset<int> bag;
long long price = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> jewel[i].second >> jewel[i].first;        
    }
    while (k--) {
        cin >> c;
        bag.insert(c);
    }
    sort(jewel, jewel + n);
    for (int i = n - 1;i >= 0;i--) {
        v = jewel[i].first;
        m = jewel[i].second;
        auto it = bag.lower_bound(m);
        if (it == bag.end()) {
            continue;
        }
        price += v;
        bag.erase(it);
    }
    cout << price;
}
