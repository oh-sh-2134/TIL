#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int n; 

vector <pair<int,int>> v; 
vector <int> ans(1000001); 
int main(void){ 
	cin >> n; 
	for(int i =0; i<n; i++){ 
		int x; cin >> x; 
		v.push_back({x,i}); 
	} 
	sort(v.begin(),v.end()); 
	int pivot = v[0].first; 
	int cnt = 0;
	ans[v[0].second] = 0; 
	for(int i = 1; i < n ; i++){ 
		if(pivot==v[i].first){ 
			ans[v[i].second] = cnt; 
		}
		else { 
			ans[v[i].second] = ++cnt; 
			pivot = v[i].first; 
		} 
	} 
	for(int i = 0; i < n ; i++)
	{ 
		cout << ans[i] << ' '; 
	} 
}
//https://www.acmicpc.net/problem/18870
//각 좌표값들을 pair로 저장하고 sort함수를 이용해서 오름차순 정렬 후에
//중복을 고려하여 값을 출력함
