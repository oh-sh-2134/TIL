#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int>freq[11];
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (auto order : orders)
	{
		for (int i = 0; i < (1 << order.size()); i++)
		{
			string menu;
			int temp = i;
		
			for (int j = 0; j < order.size(); j++)
			{
				if (temp % 2) menu += order[i];
				temp /= 2;
			}
		}
		freq[menu.size()][menu]++;
	}
	return answer;
}