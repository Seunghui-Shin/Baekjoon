#include <iostream>
#include <list>
#include <string>
using namespace std;
int n;
string str;
list<char> lst;
char order, letter;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    for (int i = 0;i < str.length();i++) {
        lst.push_back(str[i]);
    }
    list<char>::iterator iter = lst.end();
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> order;
        if (order == 'L') {
            if (iter != lst.begin()) {
                iter--;
            }
        }
        else if (order == 'D') {
            if (iter != lst.end()) {
                iter++;
            }
        }
        else if (order == 'B') {
            if (iter != lst.begin()) {
                iter--;
                iter = lst.erase(iter);
            }
        }
        else {
            cin >> letter;
            lst.insert(iter, letter);
        }
    }
    for (iter = lst.begin();iter != lst.end();iter++) {
        cout << *iter;
    }
}
