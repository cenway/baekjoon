/*
문제마다 행/열 순서가 다를 수 있으니 분명히 하자
시작점이 여러 곳이며 동시에 진행되는 경우, 시작점을 모두 큐에 넣어놓고 시작 
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int board[1001][1001];
int day[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	int n, m;
	cin >> m >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 1)
			{
				day[i][j] = 1;
				q.push({i, j});
			}
		}
	}

	if(q.empty())
	{
		cout << -1;
		return 0;
	}

	while(!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();
		
		for(int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx<0||nx>=n||ny<0||ny>=m||day[nx][ny]||board[nx][ny])
				continue;
			day[nx][ny] = day[x][y] + 1;
			board[nx][ny] = 1;
			q.push({nx,ny});
		}
	}

	int min_day = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(min_day < day[i][j])	min_day = day[i][j];
			if(!board[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << (min_day - 1);

	return 0;
}