#include <string>
#include <vector>
#include <cstring>

using namespace std;
int cache[100000][10][10];

int arr[10][10] = {
	{ 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
	{ 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
	{ 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
	{ 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
	{ 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
	{ 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
	{ 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
	{ 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
	{ 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
	{ 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};

int min(int a, int b) {
	return a > b ? b : a;
};

int moveFinger(int cnt, int left, int right, string& num) {
	//문자열 다 돌았을떄
	if (cnt == num.size()) { return 0; }

	//구한 값일떄
	if (cache[cnt][left][right]) { return cache[cnt][left][right]; }

	int cur = (num[cnt]) - '0';

	//바로 번호 누를 수 있을때
	if (left == cur || right == cur)
	{
		return cache[cnt][left][right] = 1 + moveFinger(cnt + 1, left, right, num);
	}

	return cache[cnt][left][right] = min(moveFinger(cnt + 1, cur, right, num) + arr[left][cur]
		, moveFinger(cnt + 1, left, cur, num) + arr[right][cur]);
}

int solution(string numbers) {
	memset(cache, 0, sizeof(cache));
	int answer = moveFinger(0, 4, 6, numbers);
	return answer;
}

//https://school.programmers.co.kr/learn/courses/30/lessons/136797