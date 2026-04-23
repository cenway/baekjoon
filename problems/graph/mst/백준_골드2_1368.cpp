#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

priority_queue<pair<int, int>,
			vector<pair<int, int>>,
			greater<pair<int, int>>>pq;

int paddy[301][301];
int well[301];
bool visit[301];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	well[0] = 100001;
	int min_idx = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> well[i];
		if(well[min_idx] > well[i]) min_idx = i;
	}
		
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> paddy[i][j];

	
	int cnt = 0;
	int cost = 0;

	cnt++;
	cost += well[min_idx];
	visit[min_idx] = true;
	for(int i = 1; i <= n; i++)
	{
		if(i == min_idx) continue;
		pq.push({well[i], i});
		pq.push({paddy[min_idx][i], i});
	}

	while(cnt < n)
	{
		int w, a;
		tie(w, a) = pq.top();
		pq.pop();
		if(visit[a]) continue;
		visit[a] = true;
		cost += w;
		cnt++;

		for(int i = 1; i <= n; i++)
		{
			if(i == a) continue;
			if(visit[i]) continue;
			pq.push({well[i], i});
			pq.push({paddy[a][i], i});
		}
	}

	cout << cost;
	return 0;
}
/*
우물을 하나만 파서 모든 논을 연결할 수도 있을 거고
모든 논에 우물을 팔 수도 있을 거고
우물을 파는 경우도 그냥 간선 하나로 치자
*/