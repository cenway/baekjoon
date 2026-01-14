//k번만 특수한 움직임이 가능하고
//나머지는 일반적인 움직임
//마치 벽 부수고 이동하기와 비슷한 듯

#include <iostream>
#include <queue>

using namespace std;

bool map[201][201];
int dist[201][201][31];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dhx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dhy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

typedef struct
{
	int x;
	int y;
	int horse;
}p;

int main() {
	// 코드 작성

	int k, n, m;
	cin >> k >> m >> n;
	if(n == 1 && m == 1)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> map[i][j];
	
	queue<p>q;
	dist[0][0][k] = 1;
	q.push({0, 0, k});

	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int horse = q.front().horse;
		q.pop();
		//일반 동작
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nhorse = horse;
			if(nx == n-1 && ny == m-1)
			{
				cout << dist[x][y][horse];
				return 0;
			}

			if(nx<0||ny<0||nx>=n||ny>=m)
				continue;
			if(map[nx][ny]||dist[nx][ny][nhorse])
				continue;
			q.push({nx, ny, nhorse});
			dist[nx][ny][nhorse] = dist[x][y][horse] + 1;
		}
		//말 동작(헷갈려서 나눔)
		if(horse)
		{
			for(int i = 0; i < 8; i++)
			{
				int nx = x + dhx[i];
				int ny = y + dhy[i];
				int nhorse = horse;
				if(nx == n-1 && ny == m-1)
				{
					cout << dist[x][y][horse];
					return 0;
				}

				if(nx<0||ny<0||nx>=n||ny>=m)
					continue;
				if(map[nx][ny]||dist[nx][ny][nhorse - 1])
					continue;
				q.push({nx, ny, nhorse - 1});
				dist[nx][ny][nhorse - 1] = dist[x][y][horse] + 1;
			}
		}
		
	}
	cout << -1;

	return 0;
}