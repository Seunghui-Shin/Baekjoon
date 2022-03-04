#include <iostream>
#include <string>
using namespace std;
string str;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	for (char i = 'a';i <='z';i++) {
		int count = 0;
		for (int j = 0;j < str.length();j++) {
			if (i == str[j]) {
				count++;
			}
		}
		cout << count << " ";
	}
}
