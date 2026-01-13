/*
서클을 찾으면 서클 인원을 제외한 나머지는 모두 팀이 없는 인원들
무의미한 탐색이 서클 탐색을 방해하지 않기 위해 첫 노드는 visit 안 해줌
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		bool visit[100001] = {false, };
		queue<pair<int, int>> q;
		int n;
		int ans;
		cin >> n;

		ans = n;
		vector<vector<int>> v(n+1);
		for(int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			v[tmp].push_back(i);
		}

		for(int i = 1; i <= n; i++)
		{
			if(!visit[i])
			{
				q.push({i, 1});
			}	
			while(!q.empty())
			{
				int next = q.front().first;
				int num = q.front().second;
				q.pop();
				if(v[next].empty())
				{
					visit[next] = true;
					continue;
				}
				for(const auto& a:v[next])
				{
					if(!visit[a])
					{
						q.push({a, num + 1});
						visit[a] = true;
						if(a == i)
						{
							ans -= num;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
