#include <iostream>
using namespace std;
int room = 0, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    n--;
    while (0 < (n -= 6 * room)) {
        room++;
    }
    cout << room + 1;
}
