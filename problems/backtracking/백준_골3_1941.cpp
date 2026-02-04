//조합으로 7칸을 골라내고
//그 중 조건에 맞는 케이스 만큼 ++ans해서 답 찾기
//next_permutation을 조합으로 활용함
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

char map[5][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			cin >> map[i][j];

	int arr[25] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int ans = 0;

	do {
		int s = 0;
		int cnt = 0, start;
		bool flag = false;
		bool visit[5][5] = {0, };
    	for(int i = 0; i < 25; i++)
		{
			if(arr[i]) continue;

			++cnt;
			if(map[i/5][i%5] == 'S') ++s;
			if(cnt - s >= 4)
			{
				flag = true;
				break;
			}
			visit[i/5][i%5] = true;
			start = i;
    	}
		if(flag) continue;

		queue<pair<int, int>> q;
		q.push({start/5, start%5});
		visit[start/5][start%5] = false;
		cnt = 6;
		while(!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx<0||nx>=5||ny<0||ny>=5||!visit[nx][ny])
					continue;
				q.push({nx, ny});
				visit[nx][ny] = false;
				--cnt;
			}
		}
		if(!cnt) ++ans;
	}while(next_permutation(arr, arr+25));

	cout << ans;
	return 0;
}

//5*5 중 7개를 조합으로 골라내고

//이 중 S가 4개 이하면 쳐내
//if (scnt + (7 - cnt) < 4) continue;
//또 연결되어 있지 않으면 쳐내
//이 연결을 어떻게 확인할까
