#include <iostream>
#include <queue>

using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int>v[1001];
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int ans = 0;
	queue<int> q;
	bool visit[1001] = {0,};

	for(int i = 1; i <= n; i++)
	{
		if(visit[i]) continue;
		q.push(i);
		visit[i] = true;
		ans++;
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for(auto k : v[x])
			{
				if(visit[k]) continue;
				visit[k] = true;
				q.push(k);
			}
		}
	}

	cout << ans;

	return 0;
}