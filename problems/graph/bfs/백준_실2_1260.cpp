#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool visit_d[1001];
bool visit_b[1001];

vector<int> v[1001];
void dfs(int f)
{
	for(auto k : v[f])
	{
		if(visit_d[k]) continue;
		visit_d[k] = true;
		cout << k << ' ';
		dfs(k);
	}
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, f;
	cin >> n >> m >> f;

	
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	visit_d[f] = true;
	cout << f << ' ';
	dfs(f);
	cout << '\n';

	queue<int> q;
	cout << f << ' ';
	visit_b[f] = true;
	q.push(f);
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		for(auto p:v[k])
		{
			if(visit_b[p]) continue;
			visit_b[p] = true;
			q.push(p);
			cout << p << ' ';
		}
	}

	return 0;
}