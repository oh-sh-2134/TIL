#include<iostream>

using namespace std;

int N;
void Input() {
	cin >> N;
}

int solution(int n) {
	int cnt = 0;

	if (n < 100)
		return n;
	else
	{
		for (int i = 1; i <= n / 100; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if ((i - 2*j) >= 0)
				{
					if ((i * 100 + (i - j) * 10 + (i - 2 * j)) <= n)
						cnt++;
					cout << (i * 100 + (i - j) * 10 + (i - 2 * j)) << "\n";
				}

				if ((i + 2*j) < 10 && j!=0)
				{
					if ((i * 100 + (i+j)*10 + (i+2*j)) <= n)
						cnt++;
					cout << (i * 100 + (i + j) * 10 + (i + 2 * j)) << "\n";
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
//문제의 input이 1000이하로 지정이될때 위의 코드는 최대 O(100)의 복잡도를 가지지만 그 이상의 자릿수를 가지는 자연수가 들어왔을때 else문을 늘려 나가서 코드가 복잡해질 수 있지만
//자릿수가 한자리씩 늘어나도 복잡도는 +100이기때문에 복잡도 면에서는 여전히 유리할 수 있음
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
