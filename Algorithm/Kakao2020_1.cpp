#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(string s) {
	int answer = s.length();
	for (int i = 1; i <= s.length() / 2; i++)
	{
		int pos = 0;
		int len = s.length();
		for (; pos + i <= s.length();)
		{
			string unit = s.substr(pos, i);
			pos += i;
			
			int cnt = 0;
			
			for (; pos + i <= s.length();) 
			{
				if (unit == s.substr(pos, i))
				{
					cnt++;
					pos += i;
				}
				else
					break;
			}
			//압축이 가능할때 문자열의 크기를 줄임
			if (cnt > 0)
			{
				len -= i * cnt;
				if (cnt < 9)
					len += 1;
				else if (cnt < 99)
					len += 2;
				else if (cnt < 999)
					len += 3;
				else
					len += 4;

			}
			answer = min(answer, len);
		}
	}
	return answer;
}

int main(void)
{
	string s1 = "aabbaccc";
	string s2= "abcabcabcabcdededededede";
	string s3 = "ababcdcdababcdcd";
	cout << solution(s3);
}
//https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/
//문자열의 길이가 n일때 2/n 보다 크게 잘라야 함
