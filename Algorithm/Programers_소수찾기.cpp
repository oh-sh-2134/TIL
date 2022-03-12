#include <string>
#include <vector>
#include <bitset>
using namespace std;

string num, paper;
int len;
int cnt;
vector<int> nums;
bool use[7];
bitset<(1 << 25)> bit;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

void dfs(int n) {
	if (n == len)
		return;
	for (int i = 0; i < len; i++) {
		if (use[i]) continue;
		num += paper[i];
		if (bit[stoi(num)])
			if (isPrime(stoi(num)))
				cnt++;
		use[i] = true;
		bit[stoi(num)] = 0;
		dfs(n + 1);
		use[i] = false;
		num.pop_back();
	}
}

int solution(string numbers) {

	fill(use, use + 7, false);
	bit.set();
	paper = numbers;
	len = paper.length();
	for (int i = 0; i < len; i++)
		dfs(0);
	int answer = cnt;
	return answer;
}