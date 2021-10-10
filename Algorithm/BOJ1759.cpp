#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;

bool arr[26] = { 0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1 };
char alphabets[15];


void Input()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> alphabets[i];

}

void dfs(string s, int now, int depth, char alphabets[])
{

	if (depth == L)
	{
		int za = 0;
		int mo = 0;
		for (int i = 0; i < s.length(); i++)
		{

			if (arr[s[i] - 97])
				za++;

			else
				mo++;

		}
		if (za >= 2 && mo >= 1)
			cout << s << endl;

		return;
	}

	for (int i = now + 1; i <= C - L + depth; i++)
		dfs(s + alphabets[i], i, depth + 1, alphabets);




}


void soution()
{
	sort(alphabets, alphabets + C);

	string s = "";

	for (int i = 0; i <= C - L; i++)
		dfs(s + alphabets[i], i, 1, alphabets);

}

int main(void)
{
	Input();
	soution();
	return 0;
}
//https://www.acmicpc.net/problem/1759
//문제를 제대로 안읽어서 다시품... 모음 자음
// sort 부분 + C 수정;
