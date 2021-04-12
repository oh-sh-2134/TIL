#include<iostream>
#define MAX 100001
#define Moduler 9901
using namespace std;
int dp[MAX][2];
int main(void) {
	int n;
	cin >> n;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % Moduler;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % Moduler;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0] + dp[i - 1][2]) % Moduler;
	}
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % Moduler;
}
/*https://www.acmicpc.net/problem/1309
	이문제는 사자가 왼쪽우리, 오른쪽우리 , 없는경우로 나누어서 풀면되는 문제임
	1일때는 오른쪽 왼쪽 그리고 없을때 하나씩 경우 밖에 없고
	2일때는 2번우리의 왼쪽에 사자를 놓게되면 1번우리의 오른쪽에 사자가 오는 경우와 1번우리에 사자가 없는 경우 총 두가지이고,
	2번우리의 오른쪽에 사자를 놓는경우도 왼쪽과 마찬가지 이지만 아무데도 놓지 않는 경우는 1번 우리에서 오른쪽, 왼쪽, 없는경우 총 세가지의
	케이스가 포함되게 된다. 이논리로 점화식을 세우면 위와같은 점화식이 나옴
	MAX에서 0이하나가 빠져서 바운더리 에러가 났는데 식이문제인건지 PC가 문제인지 한참 찾았다...ㅠ
*/