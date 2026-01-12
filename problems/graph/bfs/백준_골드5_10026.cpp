#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

#define X first
#define Y second
#define R 0x1
#define G 0x2
#define B 0x4

using namespace std;

char board[100][100];
bool visit[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

void bfs(int, int, char );

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char tmp;
			cin >> tmp;
			if(tmp == 'R')	tmp = R;
			else if(tmp == 'G') tmp = G;
			else if(tmp == 'B') tmp = B;
			board[i][j] = tmp;
		}
	}

	int cnt1 = 0;
	//정상
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(visit[i][j]) continue;
			bfs(i, j, board[i][j]);
			cnt1++;
		}
	}

	//초기화
	memset(visit, 0, sizeof(visit));

	int cnt2 = 0;
	//색약
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(visit[i][j]) continue;
			if(board[i][j] & (R|G))
				bfs(i, j, R|G);
			else
				bfs(i, j, B);
			cnt2++;
		}
	}

	cout << cnt1 << ' ' << cnt2;
	return 0;
}

void bfs(int i, int j, char c)
{
	visit[i][j] = true;
	queue<pair<int, int>> q;
	q.push({i,j});
	while(!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx<0||nx>=n||ny<0||ny>=n||visit[nx][ny]||!(board[nx][ny] & c))
				continue;
			q.push({nx,ny});
			visit[nx][ny] = true;
		}
	}
}

//bfs를 3개랑 2개 돌려야 하는데 최대한 깔끔하게 하고 싶음
//
