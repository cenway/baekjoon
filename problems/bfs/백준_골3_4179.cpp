/*
이동하는 객체가 둘인 상황에서 bfs
같은 큐에 넣어서 같은 시간에 동작할 수 있도록 함
대신 조건이 조금 더러워짐

이 문제의 경우 지훈이보다 불을 먼저 넣고,
불이 간 곳은 지훈이가 이동하지 못 하게 하는 경우도 있음
*/
#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

char map[1001][1001];
int dist[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 'J')
			{
				q.push({i, j});
				dist[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(map[i][j] == 'F')
				q.push({i, j});
		}
	}
	
	while(!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		char me = map[x][y];
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0||nx>=n||ny<0||ny>=m)
			{
				if(me == 'J')
				{
					cout << dist[x][y];
					return 0;
				}
				continue;
			}
			if(map[nx][ny] == 'F' || map[nx][ny] == '#' )
				continue;
			if(me == 'J')
			{
				if(dist[nx][ny]) 
					continue;
				else
				{
					dist[nx][ny] = dist[x][y] + 1;
				}	
			}
			q.push({nx, ny});
			map[nx][ny] = me;
		}
		if(me == 'J') dist[x][y] = '.';
	}
	cout << "IMPOSSIBLE";
	return 0;
}

//얘는 외곽처리가 필요한 상황에 도달하면 문제 해결된 케이스
//지훈이 먼저 이동, 불이 나중에 이동해서 불이 지훈 자리에 닿으면 사망
//지훈과 불들의 시작 지점이 다름
//하나의 큐에서 지훈 먼저 넣고 그 담에 불 넣기
//불을 유도하는 케이스는 없으니 dist(=탈출시간)사용
//push할 때 맵에 표시, pop할 때 지우기
//q에서 꺼낼 때 불이 덮쳤는지 확인하기
//둘이 구분하지 말고 전 값을 가져다 덮기
//지훈이가 갔는지랑 불이 갔는지는 따로 생각
