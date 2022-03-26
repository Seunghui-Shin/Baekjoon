#include <iostream>
using namespace std;
#define max_n 27
int lc[max_n];
int rc[max_n];
int n;
char node, l, r;

void preorder(int cur) {
    cout << char(cur + 'A' - 1);
    if (lc[cur] != 0) {
        preorder(lc[cur]);
    }
    if (rc[cur] != 0) {
        preorder(rc[cur]);
    }
}

void inorder(int cur) {
    if (lc[cur] != 0) {
        inorder(lc[cur]);
    }
    cout << char(cur + 'A' - 1);
    if (rc[cur] != 0) {
        inorder(rc[cur]);
    }
}

void postorder(int cur) {
    if (lc[cur] != 0) {
        postorder(lc[cur]);
    }
    if (rc[cur] != 0) {
        postorder(rc[cur]);
    }
    cout << char(cur + 'A' - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> node >> l >> r;
        if (l != '.') {
            lc[node - 'A' + 1] = l - 'A' + 1;
        }
        if (r != '.') {
            rc[node - 'A' + 1] = r - 'A' + 1;
        }
    }
    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);
}
