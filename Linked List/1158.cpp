#include <iostream>
#include <list>
using namespace std;
int n, k;
list<int> lst;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        lst.push_back(i);
    }
    list<int>::iterator iter = lst.begin();
    cout << "<";
    while (n--) {
        for (int i = 1;i < k;i++) {
            iter++;
            if (iter == lst.end()) {
                iter = lst.begin();
            }
        }
        cout << *iter;
        iter = lst.erase(iter);
        if (lst.size() == 0) {
            break;
        }
        cout<< ", ";
        if (iter == lst.end()) {
            iter = lst.begin();
        }
    }
    cout << ">";
}
