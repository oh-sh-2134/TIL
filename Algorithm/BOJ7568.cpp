#include<iostream>
#include<vector>
using namespace std;

int arr[50][2];
int n;
void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
}

vector<int> solution() {
	vector<int> sol;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				cnt++;
		}
		sol.push_back(cnt);
	}
	return sol;
}

int main(void) 
{
	vector<int> sol;
	Input();
	sol = solution();
	for (auto e : sol) {
		cout << e << " ";
	}

}
//https://www.acmicpc.net/problem/7568
//������ ���̽��� ��ü�� ���ϸ� �� 