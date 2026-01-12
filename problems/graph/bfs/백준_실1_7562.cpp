#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int dx[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int dy[8] = {1, -1, 2, 2, 1, -1, -2, -2};

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--)
	{
		int dist[300][300] = {0,};
		queue<pair<int, int>>q;
		int l, startx, starty, endx, endy;
		int max_dist = 0;

		cin >> l >> startx >> starty >> endx >> endy;
		dist[startx][starty] = 1;
		q.push({startx, starty});

		while(!q.empty())
		{
			int x = q.front().X;
			int y = q.front().Y;
			q.pop();
			if(dist[x][y] > max_dist) max_dist = dist[x][y];
			if(x == endx && y == endy) break;
			for(int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx<0||nx>=l||ny<0||ny>=l||dist[nx][ny])
					continue;
				//여기에 케이스를 줄일 수 있는 경우를 넣을 수 있으면
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx,ny});
			}
		}
		cout << max_dist - 1 << '\n';
	}
	return 0;
}