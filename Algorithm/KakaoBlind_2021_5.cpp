#include <string>
#include <vector>
#include<iostream>
#include<string>

using namespace std;

int sec[360001];
int parsing(string s)
{
	return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
}

string solution(string play_time, string adv_time, vector<string> logs) {
	int pt = parsing(play_time);
	int at = parsing(adv_time);
	long long maxsum = 0;
	long long sum = 0;
	int maxidx = 0;
	for (auto s : logs)
	{
		int f = parsing(s.substr(0, 8));
		int e = parsing(s.substr(9, 8));
		for (int i = f; i <= e; i++)
		{
			sec[i]++;
		}
	}

	for (int i = 0; i <= at; i++)
	{
		maxsum += sec[i];
	}
	maxidx = 0;
	sum = maxsum;
	for (int i = at; i <= pt-at; i++)
	{
		sum += sec[i + 1] - sec[i - 1];
		if (maxsum < sum)
		{
			maxsum = sum;
			maxidx = i;
		}
	}
	int num = 0;
	string answer = "";
	for (int i = 3600; i >0; i /= 60)
	{
		num = maxidx / i;
		maxidx -= num * i;
		if (num < 10)
			answer += "0";
		answer += to_string(num);
		if (i != 1)
			answer += ":";
	}

	return answer;
}

int main(void)
{
	string pt = "02:03:55";
	string at = "00:14:15";
	vector<string> logs = { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" };

	cout << solution(pt, at, logs);

}