#include<iostream>
#define MAX 1000

using namespace std;

int N;
void Input() {
	cin >> N;
}

int jari(int a)
{
	int n = a;
	int cnt = 0;
	while (n != 1)
	{
		n /= 10;
		cnt++;
	}
	return cnt;
}

int solution(int n) {
	int cnt = 0;

	if (n < 100)
		return n;

	else if(n<=1000)// 3자리
	{
		int jariso = 10/jari(1000) + 1;
		for (int i = 1; i <= n / 100; i++)
		{
			for (int j = 0; j <= jariso; j++)
			{
				if ((i - 2*j) >= 0)
				{
					if ((i * 100 + (i - j) * 10 + (i - 2 * j)) <= n)
						cnt++;
				}

				if ((i + 2*j) < 10 && j!=0)
				{
					if ((i * 100 + (i+j)*10 + (i+2*j)) <= n)
						cnt++;
				}
				

			}
		}
		return (cnt + 99);
	}

	return cnt;
}

int main(void)
{
	Input();
	int sol = solution(N);

	cout << sol;

	return 0;
}
//https://www.acmicpc.net/problem/1065
//한수의 특성상 자릿수가 늘어 날 수록 가질 수 있는 등차는 급격하게 줄어들고 5자리 이상이 되면 가질 수 있는 등차는 0, 1, 2밖에 없다. 심지어 2차이는 86420밖에 존재하지 않는다.
//자릿수에 따라 발생할 수 있는 등차를 적용하여 에초에 불가능한 케이스를 배제하여 브루트 포스 알고리즘 + 백트래킹(??) 적용
//문제의 input이 1000이하로 지정이될때 위의 코드는 최대 O(40)의 복잡도를 가지지만 그 이상의 자릿수를 가지는 자연수가 들어왔을때 else문을 늘려 나가서 코드가 복잡해질 수 있지만
//자릿수가 늘어나도 복잡도는 유리할 수 있음 (속도 체감은 불가능 해보임)
//아래는 O(N)을 가지는 코드임 코드가 간결하여 가독성이 우월해보임

/*
	for(int i=1;i<=N;i++)
	{
		if(i<100)count++;
		else{
			a=i/100;
			b=(i%100)/10;
			c=(i%100)%10;
			if((c-b)==(b-a))count++;
		}
	}
*/
