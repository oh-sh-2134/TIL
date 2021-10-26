#include <string>
#include <vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;


int htom(string s)
{
	int h = stoi(s.substr(0,2));
	int m = stoi(s.substr(3, 2));

	return h * 60 + m;
}

int fee[10000];
int inf[10000];
vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	int nt = fees[0];
	int nf = fees[1];
	int ut = fees[2];
	int uf = fees[3];
	fill(inf, inf + 10000, -1);
	for (auto info : records)
	{
		int idx1 = 0;
		int idx2 = info.find(" ", idx1);
		int t = htom(info.substr(idx1, idx2 - idx1));
		idx1 = idx2 + 1;
		idx2 = info.find(" ", idx1);

		int numpad = stoi(info.substr(idx1, idx2 - idx1));
		idx1 = idx2 + 1;

		string cmd = info.substr(idx1, info.length() - idx1);

		if (cmd == "IN")
			inf[numpad] = t;
		else
		{
			int time = t - inf[numpad];
			fee[numpad] += time;

			inf[numpad] = -1;
			
		}
	}

	for (int i = 0; i < 10000; i++)
	{
		if (inf[i] != -1)
		{
			int time = 1439 - inf[i];
			
			fee[i] += time;
			inf[i] = -1;
		}

		if (fee[i] != 0)
		{
			int temp = 0;
			int total = nf;
			if (fee[i] - nt > 0)
			{
				fee[i] -= nt;
				if (fee[i] % ut > 0)
					total += (fee[i] / ut + 1)*uf;
				else
					total += (fee[i] / ut * uf);
			}
			answer.push_back(total);
		}
	}
	return answer;
}

int main(void)
{
	vector<int> i = { 1, 461, 1, 10 };
	vector<string>v = { "00:00 1234 IN" };
	for (auto a : solution(i, v))
	{
		cout << a << "\n";
	}
}