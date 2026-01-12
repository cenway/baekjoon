#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char board[1000][1000];
int dist[1000][1000][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct
{
	int X;
	int Y;
	bool crash = false;
}p;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<p>q;
	int n, m;
	cin >> n >> m;
	if(n == 1 || m == 1)
	{
		cout << 1;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			board[i][j] -= '0';
		}	
	}
	
	q.push({0, 0, false});
	dist[0][0][0] = 1;
	while(!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		bool crash = q.front().crash;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			bool ncrash = crash;
			if(nx<0||nx>=n||ny<0||ny>=m||dist[nx][ny][ncrash])
				continue;
			
			if(board[nx][ny])
			{
				if(ncrash) continue;
				else ncrash = true;
			}
			dist[nx][ny][ncrash] = dist[x][y][crash] + 1;
			if(nx == n - 1 && ny == m - 1)
			{
				cout << dist[nx][ny][ncrash];
				return 0;
			}
			q.push({nx, ny, ncrash});	
		}
	}
	cout << -1;
	
	return 0;
}
//뚫은 놈이 앞서 간건지 아닌건지