#include<iostream>
#include<algorithm>
using namespace std;

char arry[26][26];
bool visited[26][26];
int index[323];

int N;
int cnt;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int y,int x){
	visited[y][x]=true;
	for(int i=0;i<4;i++){
		int ny=dy[i]+y;
		int nx=dx[i]+x;
		if(!(nx<0 || nx>=N || ny<0 || ny>=N)){
			if(!visited[ny][nx] && arry[y][x] ==arry[ny][nx]){
					index[cnt]++;
					dfs(ny,nx);
					
			}
		}
	}
}

/*void merge(int t[], int s,int m,int e){
	int table[25];
	int p=s;
	int st=s;
	int mid=m+1;
	while(st<=m && mid<=e){
		if(t[st]>t[mid])
			table[p++]=t[st++];
		
		else
			table[p++]=t[mid++];
	}
			
	while(st<=m)
		table[p++]=t[st++];
	while(mid<=e)
		table[p++]=t[mid++];
		
	for(int i=s; i<=e;i++){
		t[i]=table[i];
	}

}

void mergeSort(int t[],int s,int e){
	if(s<e){
		int middle = s+e/2;
		mergeSort(t,s,middle);
		mergeSort(t,middle+1,e);
		merge(t,s,middle,e);
	}
}
*/


int main(void){

	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0; j<N ; j++){
			cin>>arry[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0; j<N ; j++){
			if(!visited[i][j] && arry[i][j] != '0'){
				index[cnt]++;
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout << cnt <<"\n";
	sort(index,index+cnt);
	//mergeSort(index,0,cnt-1);
	for(int i=0;i<cnt;i++){
		cout << index[i]<<"\n";
	}


}

//https://www.acmicpc.net/problem/2667
//메모리 초과를 받았는데 정확히 왜 메모리 초과가 났는지 확인이 필요해보임