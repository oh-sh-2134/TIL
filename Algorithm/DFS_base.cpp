#include<iostream>
#include<queue>
#include<vector>
 
using namespace std;
 
int check[7];
vector<int>node[7];
 
void dfs(int x){
	if(check[x]) return;
	check[x]=true;
	cout << x <<" ";
	for(int i=0;i<node[x].size();i++){
		int y=node[x][i];
		dfs(y);
	}
}
 
int main(void){
	node[1].push_back(2);
	node[2].push_back(1);

	node[1].push_back(3);
	node[3].push_back(1);
 
	node[2].push_back(3);
	node[3].push_back(2);
 
	node[4].push_back(2);
	node[2].push_back(4);
 
	node[5].push_back(2);
	node[2].push_back(5);
 
	node[4].push_back(5);
	node[5].push_back(4);
 
	node[3].push_back(6);
	node[6].push_back(3);
 
	node[3].push_back(7);
	node[7].push_back(3);
 
	node[6].push_back(7);
	node[7].push_back(6);
 
	dfs(1);
 
}