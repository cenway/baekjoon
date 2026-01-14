#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int board[300][300] = {0, };
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	
	int year = 0;
	while(++year)
	{
		queue<pair<int, int>> q;
		bool visit[300][300] = {0,};
		bool start = false;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(board[i][j] && !visit[i][j])
				{
					q.push({i, j});
					visit[i][j] = true;

					//시작점이 두 곳이다? 그럼 끝
					if(start)
					{
						cout << year-1;
						return 0;
					}
					start = true;

					while(!q.empty())
					{
						int x = q.front().X;
						int y = q.front().Y;
						int cnt = 0;
						q.pop();
						for(int k = 0; k < 4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							if(nx<0||ny<0||nx>=n||ny>=m)
								continue;
							if(visit[nx][ny])
								continue;
							if(!board[nx][ny])
								cnt++;
							else
							{
								q.push({nx, ny});
								visit[nx][ny] = true;
							}
						}
						board[x][y] -= cnt;
						if(board[x][y] < 0) board[x][y] = 0;
					}
				}
			}
		}
		if(!start)
		{
			cout << 0;
			return 0;
		}
	}
	return 0;
}
//처음 잡히는 곳부터 사방을 돌면서 0갯수 만큼 지우는데
//옆에놈이 같은 회차에 녹아 0이됐으면 신경쓰지 않기(어차피 visit)
//매 회차에 시작점이 두 번 잡히면 그 때가 최소값
//시작점이 아예 안 잡히면 0