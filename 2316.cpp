#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//bool map[401][401];
vector<int> v[401];
bool visit[401];

int main() {
	// 코드 작성
	int n, m;
	cin >> n >> m;
	while(m--)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}

	int min_width = 100000;
	int width = 0;
	int arrive = 0;
	int depth[2] = {0, };
	bool depth_toggle = false;

	queue<int> q;
	visit[1] = true;
	q.push(1);
	depth[depth_toggle]++;

	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		depth[depth_toggle]--;

		for(auto y:v[x])
		{
			//그냥 2라고 냅다 ++하면 안 됨
			//언제가 문제냐.
			//1. 애초에 2랑 연결되면 이 노드는 거기서 끝
			//2. 3 -> {4, 5} -> 2 처럼 되면 하나만 살려야 되는데
			//ㄴ심지어는 3->{4, 5}->{2, 6}->2 도 가능
			//1.은 해결 바로 되는데
			//
			if(y == 2)
			{
				arrive++;
				continue;
			}
			if(visit[y]) continue;
			q.push(y);
			visit[y] = true;
			depth[!depth_toggle]++;
			width++;
		}

		if(!q.empty()&&!depth[depth_toggle])
		{
			cout << min_width << '\n';
			depth_toggle = !depth_toggle;
			if(min_width > width) min_width = width;
			width = 0;
		}
	}
	cout << min_width << ' ';
	arrive += min_width;
	cout << arrive;
	return 0;
}

/*
같은 도시를 거치지 않고 최대한 많이 왕복
bfs로 안 되나?
중간에 경로가 줄었음을 어떻게 확인
ㄴbfs로 depth별로 폭의 최소값을

문제. 모든 경로가 같은 depth는 아님
따라서, 어떻게 하냐. dedpth가 끊긴 애들을 뒤로 계속 연장?
2를 만나는 경우에는 그냥 더해주면 될 거 같은데
아니면?
1 3 4
1 5 6 4
ㄴ이런 경우는? 어차피 길 하나니까 134가 틀어막아주겠네
ㄴ그럼 그냥 2를 만난 경우만 최종 min_width에 더해주면 되겠네

자꾸 min_width가 0이 됨.
ㄴ 끝을 잘 내줘야 할 거 같음. 
그리고 min_width 1을 찍었따가 갈라져서 2에 도달하는 경우는 어떻게?

*/