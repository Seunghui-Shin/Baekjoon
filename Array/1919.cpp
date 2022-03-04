#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
string a, b;
#define max_alpha 26
int arr1[max_alpha];
int arr2[max_alpha];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    for (int i = 0;i < a.length();i++) {
        arr1[a[i] - 'a']++;
    }
    for (int i = 0;i < b.length();i++) {
        arr2[b[i] - 'a']++;
    }
    int count = 0;
    for (int i = 0;i < max_alpha;i++) {
        if (arr1[i] != arr2[i]) {
            count += abs(arr1[i] - arr2[i]);
        }
    }
    cout << count;
    return 0;
}
