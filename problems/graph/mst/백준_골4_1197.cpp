#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

priority_queue<tuple<int, int, int>,
			vector<tuple<int, int, int>>,
			greater<tuple<int, int, int>>> pq;

vector<pair<int, int>> node[10001];
bool visit[10001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	for(int i = 0; i < e; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		node[a].push_back({w, b});
		node[b].push_back({w, a});
	}

	int cnt = 0;
	int cost = 0;
	for(auto f : node[1])
		pq.push({f.first, f.second, 1});

	visit[1] = true;
	while(cnt < v-1)
	{
		int w, a, b;
		tie(w, a, b) = pq.top();
		pq.pop();
		if(visit[a]) continue;
		cnt++;
		cost += w;
		visit[a] = true;
		for(auto f: node[a])
		{
			if(visit[f.second]) continue;
			pq.push({f.first, f.second, a});
		}
	}


	cout << cost;

	return 0;
}