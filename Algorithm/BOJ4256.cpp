#include <vector>
#include <iostream>

using namespace std;

int T;
int n;
vector<int> preorder;
vector<int> v_in;

void input() {
	preorder = vector<int>(n);
	v_in = vector<int>(n);

	for (int j = 0; j < n; ++j) {
		cin >> preorder[j];
	}
	for (int j = 0; j < n; ++j) {
		cin >> v_in[j];
	}
		
}

void postorder(int start, int end, int pos) {
	for (int i = start; i < end; ++i) {
		if (v_in[i] == preorder[pos]) {
			postorder(start, i, pos + 1);
			postorder(i + 1, end, pos + 1 + i - start);
			cout << preorder[pos] << ' ';
		}
	}
}

void solution() {
	postorder(0, n, 0);
	cout << "\n";
}


int main() {
	cin >> T;

	for (int i = 0; i < T; ++i) {
		input();
		solution();
	}
}