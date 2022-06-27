#include <string>
#include <vector>
using namespace std;

//bit 개수 return
int getBitCount(int n) {
	int bitCnt = 0;
	while (n) {
		if (n % 2)
			bitCnt++;
		n /= 2;
	}
	return bitCnt;
}

int solution(int n) {
	int bitCnt = getBitCount(n);
	//비트 개수가 같은 수를 찾을때까지 반복
	while (1) {
		n++;
		if (bitCnt == getBitCount(n))
			break;
	}
	int answer = n;
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12911