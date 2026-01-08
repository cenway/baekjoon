//붙어서 들어올 땐 char로 입력 받으면 하나씩 끊어짐(반드시 -'0')
//bfs에서 거리를 재는 다양한 방법을 시도했지만 용량 부족이 아니라면
//board와 같은 배열을 추가로 만들어 각 칸 마다 거리를 남기자
//dist를 -1로 초기화 해두면 visit이 필요 없음

#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

bool board[101][101];
bool visit[101][101];
int dist[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;
	q.push({0, 0});
	visit[0][0] = true; 
	dist[0][0] = 1;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}


	int min_dist = 0;
	while(!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();

		if(x == n-1 && y == m-1)
		{
			min_dist = dist[x][y];
			break;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0||nx>=n||ny<0||ny>=m||visit[nx][ny]||!board[nx][ny])
				continue;
			
			q.push({nx, ny});
			dist[nx][ny] = dist[x][y] + 1;
			visit[nx][ny] = true;
		}
	}
	cout << min_dist;

	return 0;
}