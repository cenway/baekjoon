//덩어리 간 거리 측정
//굉장히 지저분하게 풀음
//dist도입이 귀찮아서 이상한 짓을 하게 됐는데
//dist만 쓰면 바로 풀림. 양쪽의 dist를 더하면 거리
#include <iostream>
#include <queue>

#define X first
#define Y second
using namespace std;

int map[101][101];
int day[2];
bool day_toggle = false;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	//땅을 -1로 받기
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if(map[i][j])
				map[i][j] -= 2;
		}
	}
	//섬 별로 번호 부여
	queue<pair<int, int>>qinit;
	queue<pair<int, int>>q;
	int cnt = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(map[i][j] == -1)
			{
				qinit.push({i, j});
				q.push({i,j});
				day[day_toggle]++; 
				map[i][j] = cnt;
				while(!qinit.empty())
				{
					int x = qinit.front().X;
					int y = qinit.front().Y;
					qinit.pop();
					for(int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if(nx<0||ny<0||nx>=n||ny>=n)
							continue;
						if(!map[nx][ny])
							continue;
						if(map[nx][ny] == -1)
						{
							map[nx][ny] = cnt;
							qinit.push({nx, ny});
							q.push({nx, ny});
							day[day_toggle]++;
						}
					}
				}
				cnt++;
			}
		}
	}

	int date = 1;
	int min_date = 2*n;
	//땅 넓혀가면서 닿으면 끝
	while(!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0||ny<0||nx>=n||ny>=n)
				continue;
			if(map[nx][ny]==map[x][y])
				continue;
			else if(map[nx][ny])
			{
				//min_date 따져서 최소값
				if(map[nx][ny] < map[x][y])
					min_date = (date*2 -1 < min_date)? date*2 -1 : min_date;
				else
					min_date = ((date-1)*2 < min_date)? (date-1)*2 : min_date;

			}
			else
			{
				map[nx][ny] = map[x][y];
				q.push({nx,ny});
				day[!day_toggle]++;
			}
		}
		day[day_toggle]--;

		if(!day[day_toggle])
		{
			if(min_date < 2*n)
			{
				cout << min_date;
				return 0;
			}
			day_toggle = !day_toggle;
			date++;
		}

	
	}



	return 0;
}
//바다 중에서 땅과 인접한 곳부터 시작해
//매일 땅을 넓혀나가다가
//어차피 대각으로는 못 움직임을 기억하자
//bfs로 덩어리 마다 번호를 매기고 다른 번호의 땅이 닿을 때까지

//우선 bfs해서 땅 찾으며 모든 땅을 q에 넣고 땅에 칠하기
//*****비상**********
//전날 닿았는데 모르다가 담날 다른 땅이 먼저 닿는 판정 발생
//하루 단위로 최소값을 추산하기로 함