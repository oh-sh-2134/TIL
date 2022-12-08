#include <string>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <queue>
using namespace std;
string conv(string city) {
	string s = "";
	for (auto c : city) { s += tolower(c); }
	return s;
}
int solution(int cacheSize, vector<string> cities) {

	if (cacheSize == 0) {return cities.size() * 5;}
	int answer = 0;
	int tempcacheSize = 0;
	vector<string> cach;

	for (auto city : cities)
	{
		city = conv(city);
		auto it = find(cach.begin(), cach.end(), city);
		//cach miss
		if (it == cach.end())
		{
			answer += 5;
			if (cach.size() >= cacheSize)
				cach.erase(cach.begin());
		}
		//cach hit
		else
		{
			answer += 1;
			if (cach.size() >= cacheSize)
				cach.erase(it);
		}
		cach.push_back(city);

	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/17680