#include <iostream>
#include <string>
#include <list>
using namespace std;
int n;
string str;

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> str;
        list<char> lst = {};
        list<char>::iterator iter = lst.begin();
        for (int j = 0;j < str.length();j++) {
            if (str[j] == '<') {
                if (iter != lst.begin()) {
                    iter--;
                }
            }
            else if (str[j] == '>') {
                if (iter != lst.end()) {
                    iter++;
                }
            }
            else if (str[j] == '-') {
                if (iter != lst.begin()) {
                    iter--;
                    iter = lst.erase(iter);
                }
            }
            else {
                lst.insert(iter, str[j]);
            }
        }
        for (iter = lst.begin();iter != lst.end();iter++) {
            cout << *iter;
        }
        cout << "\n";
    }
}
