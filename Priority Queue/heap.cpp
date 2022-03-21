#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x) {
	heap[sz] = x;
	int tail = sz;
	while (tail != 0) {
		if (heap[(tail-1) / 2] > heap[tail]) {
			swap(heap[(tail - 1) / 2], heap[tail]);
			tail = (tail - 1) / 2;
		}
		else {
			break;
		}
	}
	sz++;
}

int top() {
	return heap[0];
}

void pop() {
	heap[0] = heap[sz - 1];
	int root = 0;
	while (2*root+1 < sz) {
		int lc = 2 * root + 1, rc = 2 * root + 2;
		int small = lc;
		if (rc < sz && heap[rc] < heap[lc]) {
			small = rc;
		}
		if (heap[small] < heap[root]) {
			swap(heap[small], heap[root]);
			root = small;
		}
		else {
			break;
		}
	}
	sz--;
}

void test() {
	push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
	cout << top() << '\n'; // 2
	pop(); // {10, 5, 9}
	pop(); // {10, 9}
	cout << top() << '\n'; // 9
	push(5); push(15); // {10, 9, 5, 15}
	cout << top() << '\n'; // 5
	pop(); // {10, 9, 15}
	cout << top() << '\n'; // 9
}

int main() {
	test();
}
