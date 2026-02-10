#include <iostream>
#include <vector>
using namespace std;

int map[8][8];
bool visit[8][8];
int n, m, cnt;
vector<pair<int, int>> v[7];
vector<pair<int, int>> vv;

int dir[6][7] =
{//x+, y+, x-, y-
	{0}, {1,0,0,0,1,0,0}, {1,0,1,0,1,0,1}, {1,1,0,0,1,1,0}, {1,1,1,0,1,1,1}, {1,1,1,1,1,1,1}
};
//배열을 이동시키며 확인
//아 이거 x, y로 어떻게 하지
//배열을 또 만들어?dx랑 dy로?

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
	for(int k = 5; k >= 1; k--)
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
				while(1)
				{
					nx += dx[z];
					ny += dy[z];
					if(nx<0||ny<0||nx>=n||ny>=m||map[nx][ny])
						break;
					if(visit[nx][ny])
						continue;
					ncnt++;
					//칸 벗어나는지, 멈출 칸인지 break
					//이미 먹힌 칸이면 continue
					//칸 수
				}
			}
			
		}

	cout << cnt;
	return 0;
}

//일단 0들어올 때 마다 cnt++
//높은 숫자부터 해서 5번 하자
//visit칸을 체크하며 값이 더 높게 나오는 쪽으로
//그냥 q나 벡터에 입력 별 좌표를 저장할까
//거리 구하는 부분
//방향 선택하는 부분
//ㄴ가장 많은 칸이 선택된 인덱스를 저장 
//visit 찍고 cnt 빼는 부분


for(int k = 5; k >= 1; k--)
	{
		for(auto i = v[k].begin(); i != v[k].end(); i++)
		{
			int x = i->first;
			int y = i->second;
			int max_dir = 0;
			int max_cnt = 0;
			//보는 방향 4개
			for(int j = 0; j < 4; j++)
			{
				int *ndir = &(dir[k][j]);
				int dx[4] = {ndir[0], 0, -ndir[2], 0};
				int dy[4] = {0, ndir[1], 0, -ndir[3]};
				int ncnt = 0;
				//보는 방향 고정 후 4방향에 대해 체크
				for(int z = 0; z < 4; z++)
				{
					int nx = x;
					int ny = y;
					while(1)
					{
						nx += dx[z];
						ny += dy[z];
						if(nx<0||ny<0||nx>=n||ny>=m||map[nx][ny])
							break;
						if(visit[nx][ny])
							continue;
						ncnt++;
						//칸 벗어나는지, 멈출 칸인지 break
						//이미 먹힌 칸이면 continue
						//칸 수
					}
				}
				if(max_cnt < ncnt)
				{
					max_cnt = ncnt;
					max_dir = j;
				}
				
			}
			//최대 방향에 대해 실제로 진행
			cnt -= max_cnt;
			//함수화 하자
			
		}
	}