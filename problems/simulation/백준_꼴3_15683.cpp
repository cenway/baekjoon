#include <iostream>
#include <vector>
using namespace std;

int map[8][8];
bool visit[8][8];
int n, m, cnt;
vector<pair<int, int>> v[7];
vector<pair<int, int>> vv;
unsigned int selected;

int dir[6][7] =
{//x+, y+, x-, y-
	{0}, {1,0,0,0,1,0,0}, {1,0,1,0,1,0,1}, {1,1,0,0,1,1,0}, {1,1,1,0,1,1,1}, {1,1,1,1,1,1,1}
};
//배열을 이동시키며 확인
//아 이거 x, y로 어떻게 하지
//배열을 또 만들어?dx랑 dy로?

void func(int depth, int min_cnt, bool visited[8][8])
{
	if(!min_cnt)
	{
		cout << 0;
		exit(0);
	}
	if(depth > vv.size())
	{
		if(min_cnt < cnt) cnt = min_cnt;
		
		return;
	}

	int i = depth-1;
	int x = vv[i].first;
	int y = vv[i].second;
	for(int j = 0; j < 4; j++)
	{
		bool new_visited[8][8];
		copy(&visited[0][0], &visited[0][0]+64, &new_visited[0][0]);
		int *ndir = &(dir[map[x][y]][j]);
		int dx[4] = {ndir[0], 0, -ndir[2], 0};
		int dy[4] = {0, ndir[1], 0, -ndir[3]};
		int ncnt = 0;
		//보는 방향 고정 후 4방향에 대해 체크
		for(int z = 0; z < 4; z++)
		{
			int nx = x;
			int ny = y;
			if(!dx[z]&&!dy[z]) continue;
			while(1)
			{
				nx += dx[z];
				ny += dy[z];
				if(nx<0||ny<0||nx>=n||ny>=m||map[nx][ny]==6)
					break;
				if(new_visited[nx][ny])
					continue;
				ncnt++;
				new_visited[nx][ny] = true;
				//칸 벗어나는지, 멈출 칸인지 break
				//이미 먹힌 칸이면 continue
				//칸 수
			}
		}
		func(depth+1,min_cnt - ncnt, new_visited);
	}		
	
}

int main() {
	// 코드 작성
	//입력 검증 완료
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if(map[i][j])
			{
				visit[i][j] = true;
				v[map[i][j]].push_back({i, j});
			} 
			else cnt++;
		}
	}
	
	//입력 옮겨 심기
	for(int k = 4; k >= 1; k--)
		for(auto i = v[k].begin(); i != v[k].end(); i++)
			vv.push_back({i->first, i->second});

	//5는 먼저 실행하고
	//1~4를 백트래킹으로 구성
	
	for(auto i = v[5].begin(); i != v[5].end(); i++)
	{
		int x = i->first;
		int y = i->second;
		
		int *ndir = &(dir[5][0]);
		int dx[4] = {ndir[0], 0, -ndir[2], 0};
		int dy[4] = {0, ndir[1], 0, -ndir[3]};
		int ncnt = 0;
		//보는 방향 고정 후 4방향에 대해 체크
		for(int z = 0; z < 4; z++)
		{
			int nx = x;
			int ny = y;
			if(!dx[z]&&!dy[z]) continue;
			while(1)
			{
				nx += dx[z];
				ny += dy[z];
				if(nx<0||ny<0||nx>=n||ny>=m||map[nx][ny]==6)
					break;
				if(visit[nx][ny])
					continue;
				ncnt++;
				visit[nx][ny] = true;
				//칸 벗어나는지, 멈출 칸인지 break
				//이미 먹힌 칸이면 continue
				//칸 수
			}
		}
		cnt -= ncnt;
	}
	func(1,cnt, visit);

	cout << cnt;
	return 0;
}