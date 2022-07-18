#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

class point {
public:
	int y;
	int x;
	point(int a, int b) {
		y = a;
		x = b;
	}
};

char arr[101][101];
bool visited[101][101];
int r, c;
int n;
vector<int> nums;
vector<point> cluster;
int mx[4] = { 0,0,-1,1 };
int my[4] = { 1,-1,0,0 };




void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		nums.push_back(k);
	}
}

//막대기 던지는 로직
void throwStick(int i) {
	if (i < 0) {
		i *= -1;
		for (int j = c - 1; j >= 0; j--) {
			if (arr[i][j] == 'x') {
				arr[i][j] = '.';
				break;
			}
		}
	}
	else{
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'x') {
				arr[i][j] = '.';
				break;
			}
		}
	}
	
}

//땅에 붙은 미네랄 방문처리
void bfs(int a, int b) {
	queue<point>q;
	q.push(point(a, b));
	visited[a][b] = true;
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = p.y + my[i];
			int x = p.x + mx[i];
			if (y >= r || y < 0 || x >= c || x < 0) continue;
			if (arr[y][x] == '.') continue;
			if (visited[y][x]) continue;
			visited[y][x] = true;
			q.push(point(y, x));
		}
	}

}

//미네랄 아래로 움직일 수 있는 최대 칸수 반환
int findMoveCnt() {
	int cnt = 987654321;
	for (int i = 0; i < cluster.size(); i++) {
		int moveCnt = 0;
		point p = cluster[i];
		for (int j = p.y+1; j < r; j++) {
			//클러스터 미네랄과 닿을시(클러스터인 미네랄과 닿는다는 것은 moveCnt가 의미 없다는 것
			if (arr[j][p.x] == 'x' && !visited[j][p.x]) {
				moveCnt = 0;
				break;
			}

			//바닥에 닿은 미네랄과 닿을시
			if (arr[j][p.x] == 'x' && visited[j][p.x]) break;
			moveCnt++;
		}
		if (moveCnt != 0)
			cnt = min(cnt, moveCnt);
	}
	return cnt;
}

//클러스터를 moveCnt만큼 아래로 이동시켜서 다시 그림
void redraw(int moveCnt) {
	for (auto iter : cluster) 
		arr[iter.y][iter.x] = '.';

	for (auto iter : cluster)
		arr[iter.y + moveCnt][iter.x] = 'x';
}

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}


void solution() {
	for (int i = 0; i < nums.size(); i++) {
		//초기화
		cluster.clear();
		memset(visited, false, sizeof(visited));
		int h = r - nums[i];
		if (i % 2)
			h *= -1;
		//막대기 던지기
		throwStick(h);
		
		//땅에 붙은 미네랄 방문처리
		for (int i = 0; i < c; i++) {
			if(!visited[r-1][i])
				bfs(r-1, i);
		}

		//클러스터의 존재 확인
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 'x' && !visited[i][j])
					cluster.push_back(point(i, j));
			}
		}

		//클러스터가 없으면 pass
		if (cluster.size() == 0) continue;
		
		//몇칸 내려가야하는지 확인
		int moveCnt = findMoveCnt();

		//그림 다시그리기
		redraw(moveCnt);
	}
	print();
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/2933