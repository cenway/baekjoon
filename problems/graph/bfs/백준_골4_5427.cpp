#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for(int p = 0; p < t; p++)
	{
		char map[1001][1001] = {0, };
		int dist[1001][1001] = {0, };
		queue<pair<int, int>> q;
		pair<int, int> dog;
		int n, m;
		cin >> m >> n;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if(map[i][j] == '*')
					q.push({i,j});
				else if(map[i][j] == '@')
					dog = {i,j};
			}
		}

		q.push({dog.X, dog.Y});
		dist[dog.X][dog.Y] = 1;
		bool flag = true;
		while(!q.empty() && flag)
		{
			int x = q.front().X;
			int y = q.front().Y;
			q.pop();

			for(int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx<0||nx>=n||ny<0||ny>=m)
				{
					if(dist[x][y])
					{
						cout << dist[x][y];
						flag = false;
						break;
					}
					continue;
				}
				if(map[nx][ny] == '#' || map[nx][ny] == '*')
					continue;
				if(dist[x][y])
				{
					if(dist[nx][ny]) continue;
					dist[nx][ny] = dist[x][y] + 1;
					map[nx][ny] = '@';
				}
				else
					map[nx][ny] = '*';
				q.push({nx,ny});
			}
		}
		if(flag) cout << "IMPOSSIBLE" << '\n';
		else cout << '\n';
	}

	return 0;
}