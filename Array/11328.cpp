#include <iostream>
#include <string>
using namespace std;
int n;
string a, b;
#define max_alpha 26

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a >> b;
        int arr1[max_alpha] = {};
        int arr2[max_alpha] = {};
        for (int j = 0;j < a.length();j++) {
            arr1[a[j] - 'a']++;
        }
        for (int j = 0;j < b.length();j++) {
            arr2[b[j] - 'a']++;
        }
        bool check = true;
        for (int j = 0;j < max_alpha;j++) {
            if (arr1[j] != arr2[j]) {
                check = false;
            }
        }
        if (check) {
            cout << "Possible" << "\n";
        }
        else {
            cout << "Impossible" << "\n";
        }
    }
}
