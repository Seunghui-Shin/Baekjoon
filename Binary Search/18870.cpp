#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max_n 1000000
vector<int> vec;
vector<int> tmp;
int org[max_n];
int n,k;

int lower_index(int k) {
    int start = 0, end = tmp.size();
    while (start < end) {
        int mid = (start + end) / 2;
        if (tmp[mid] < k) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return start;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> org[i];
        vec.push_back(org[i]);
    }
    sort(vec.begin(),vec.end());
    for (int i = 0;i < n;i++) {
        if (i == 0 || vec[i - 1] != vec[i]) {
            tmp.push_back(vec[i]);
        }
    }
    for (int i = 0;i < n;i++) {
        cout << lower_index(org[i]) << " ";
    }
}
