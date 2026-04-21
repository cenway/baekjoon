//얼핏 설명을 보다보면, 정렬 쪽의 문제라고 생각할 수 있는데
//각 학생을 정점으로 보고, 간선으로 보면 위상정렬
#include <iostream>
#include <queue>
using namespace std;

int ind[32001];
vector<int>v[32001];
queue<int> q;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}
	for(int i = 1; i <= n; i++) if(ind[i] == 0) q.push(i);
	while(!q.empty())
	{
		int prev = q.front();
		q.pop();
		cout << prev << ' ';
		for(auto next : v[prev])
		{
			ind[next]--;
			if(ind[next] == 0) q.push(next);
		}
	}
	return 0;
}