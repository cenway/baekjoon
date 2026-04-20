#include <iostream>
#include <queue>

using namespace std;

int p[100001];
vector<int> v[100001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	p[1] = -1;
	q.push(1);
	while(!q.empty())
	{
		int parent = q.front();
		q.pop();
		for(auto child : v[parent])
		{
			if(p[child]) continue;
			p[child] = parent;
			q.push(child);
		}
	}

	for(int i = 2; i <= n; i++)
		cout << p[i] << '\n';

	return 0;
}