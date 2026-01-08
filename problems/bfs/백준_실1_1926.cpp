#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

bool board[501][501];
bool visit[501][501];

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
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	
	int num = 0;
	int max_area = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(board[i][j] && !visit[i][j])
			{
				visit[i][j] = true;
				q.push({i,j});
				num++;
				int area = 0;
				while(!q.empty())
				{
					area++;
					pair<int, int> cur = q.front();
					q.pop();
					for(int k = 0; k < 4; k++)
					{
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if(nx<0||nx>=n||ny<0||ny>=m||visit[nx][ny]||!board[nx][ny])
							continue;
						visit[nx][ny] = true;
						q.push({nx, ny});
					}
				}
				if(max_area < area)	max_area = area;

			}
		}
	}
	cout << num << '\n' << max_area;

	
	return 0;
}