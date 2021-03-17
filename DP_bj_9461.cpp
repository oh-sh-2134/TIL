#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
long long int DP[MAX];
queue<int>q;
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int n,a;
	int top=0;
	cin >> n;
	for (int i = 0; i < n; i++) { //모든케이스에서 계산하는건 DP에 맞지않음 가장 높은 수를 찾아서 그 수만큼만 DP를 구하면 됨
		cin >> a;					//나머지 케이스는 queue로 관리하여 마지막에 순서대로 출력
		q.push(a);
		top = max(top,a);
	}
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 1;
	for (int i = 3; i <= top; i++) {
		DP[i] = DP[i - 2] + DP[i - 3]; // 점화식
	}
	for (int i = 0; i < n; i++) {
		cout << DP[q.front()-1]<<"\n";
		q.pop();
	}
}
//https://www.acmicpc.net/problem/9461
//규칙을 찾아서 점화식을 잘세우면 되는 문제
//처음에는 그림을 보고 8번째까지 직접 선언하고 그 이후 부터는 DP[i] = DP[i-1] + DP[i-4] 로 구하도록 만들었는데 틀림
//종이에 써놓고 가만히보니 점화식이 잘못된걸 확인하고 수정 후 제출했는데도 틀림
//79번째에서 24억넘게 나오고 80번째에서 int 범위를 벗어남 long long 으로 제출해서 맞음