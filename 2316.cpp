#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[401];
bool visit[401];
bool arrived_stg[401];

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
	

	int arrive = 0;
	queue<pair<int, int>> q;
	visit[1] = true;
	for(auto y:v[1])
	{
		q.push({y, 0});
		visit[y] = true;
	}
	//일단 1에서 뻗어나온 애들 다 연결하고

	//여럿으로 갈라지는 경우엔 전부 낙인 찍기
	//2에 도착했을 경우, 낙인 여부를 확인하고 arrived++
	while(!q.empty())
	{
		int cnt = 0;
		bool arrived_flag = false;
		int x = q.front().first;
		int stg = q.front().second;
		q.pop();

		for(auto y:v[x])
		{
			if(!visit[y]) cnt++;
			if(y != 2) continue;
			if(!stg) arrive++;
			else if(!arrived_stg[stg])
			{
				arrived_stg[stg] = true;
				arrive++;
			}
			arrived_flag = true;
			break;
		}
		if(arrived_flag) continue;

		//다른 낙인 찍힌 놈이 앞 길을 막았을 때
		//나는 이 길이 유일하면 상관 없지
		//근데 사실 나도 낙인 찍혔으면.
		//누구의 낙인을 따라야 하는가.
		//내 낙인으로 진행하다가 같은 낙인 다른 놈이 도달하면
		//그러나 다른 낙인은 걔가 유일하게 도달할 수 있는 놈이면
		//낙인을 새거로 바꾸것도 당연히 문제가 되고
		//그렇다고 둘 다 데려가면서 낙인을 다 저장하는 거는
		//사실 상 경로를 다 저장하자는 거고

		//그럼 미리 다음 것도 봐서 막는 건
		//그럼 그 다음 거는?

		for(auto y:v[x])
		{		
			if(visit[y]) continue;

			if(cnt > 1) 
			{
				if(!stg)
					q.push({y, x});
				else
				{
					q.push({y, stg});
				}
			}
			else q.push({y,0});
			visit[y] = true;

		}
	}
	//stg를 처음 게 체크가 안 됨

	cout << arrive;
	return 0;
}

/*
같은 도시를 거치지 않고 최대한 많이 왕복
bfs로

1이후로 하나에서 갈라져 나오는 경우 징표를 달아두기
최초의 하나에 대해서만
*/

/*
8 13
1 3
1 5
1 6
1 8
3 4
4 5
4 6
5 6
5 7
8 5
7 2
2 4
6 2


8 13
1 5
1 8
1 6
1 3
3 4
2 4
4 5
4 6
5 6
5 7
6 2
7 2
8 5
15
18
16
13
54
57
62
34
72
42



13
15
16
18
34
57
62
72
42
*/