#include <iostream>
#include <queue>
using namespace std;

int dist[1000001];
bool visit[1000001];

queue<int> q;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		visit[tmp] = true;
		q.push(tmp);
	}

	while(!q.empty())
	{		
		int cur = q.front();
		q.pop();
		int dis = dist[cur] + 1;
		//1비트씩 바꿔가며 dist+1 넣기
		for(int i = 0; i < 20; i++)
		{
			int tmp = cur ^ (1 << i);
			if(tmp > n) continue;
			if(visit[tmp]) continue;
			visit[tmp] = true;
			dist[tmp] = dis;
			q.push(tmp);
		}
	}

	int ans = 0;
	for(int i = 0; i <= n; i++)
		if(ans < dist[i]) ans = dist[i];

	cout << ans;

	return 0;
}