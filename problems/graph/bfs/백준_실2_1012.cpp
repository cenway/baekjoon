//토마토 같은 경우 덩어리의 수를 새는 것이 아니기에
//입력 당시 바로 큐에 넣고 bfs하면 된다
//그러나 그림이나 이 배추 문제는 덩어리의 수가 중요하기에
//입력 당시 배열에 집어넣고 하나씩 꺼내가며 bfs하거나
//아니면 그냥 0,0부터 n,m까지 다시 찾아가도 된다

//입력 당시 q에 집어넣는 건 같은 덩어리에 멀리 있는 시작점이
//cnt를 올려버리는 문제가 생긴다.
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
	while(t--)
	{
		bool board[50][50] = {0, };
		bool visit[50][50] = {0, };
		pair<int, int> arr[2500] = {{0,0},};
		queue<pair<int, int>> q;
		int n, m, k;
		cin >> n >> m >> k;
		for(int i = 0; i < k; i++)
		{
			int tmpx, tmpy;
			cin >> tmpx >> tmpy;
			board[tmpx][tmpy] = true;
			arr[i] = {tmpx, tmpy};
		}

		int cnt = 0;
		for(int j = 0; j < k; j++)
		{
			auto i = arr[j];
			if(visit[i.X][i.Y])	continue;
			q.push({i.X, i.Y});
			visit[i.X][i.Y] = true;
			cnt++;
			
			while(!q.empty())
			{
				int x = q.front().X;
				int y = q.front().Y;
				q.pop();
				
				for(int l = 0; l < 4; l++)
				{
					int nx = x + dx[l];
					int ny = y + dy[l];
					if(nx<0||nx>=n||ny<0||ny>=m||visit[nx][ny]||!board[nx][ny])
						continue;
					visit[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}