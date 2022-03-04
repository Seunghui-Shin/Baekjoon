#include <iostream>
using namespace std;
int n, k;
#define max_sex 2
#define max_grade 7
int sex, grade;
int arr[max_sex][max_grade];

int main() {
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        cin >> sex >> grade;
        arr[sex][grade]++;
    }
    int count = 0;
    for (int i = 0;i < max_sex;i++) {
        for (int j = 1;j < max_grade;j++) {
            if (arr[i][j] == 0) {
                continue;
            }
            else {
                count += (arr[i][j] - 1) / k + 1;
            }
        }
    }
    cout << count;
    return 0;
}
