/*
bfs 중 사방으로 돌지 않는 유형
for 문법에 range-based-for는 컨테이너를 넣어도 되지만
직접 {}로 배열을 만들어 넣어줘도 됨
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visit[100000];

int main()
{
	queue<int> q;

	int n, k;
	cin >> n >> k;
	if(n > k)
	{
		cout << n - k;
		return 0;
	}

	q.push(n);
	visit[n] = 1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		if(x == k)
		{
			cout << visit[x] - 1;
			return 0;
		}
		
		for(int nxt: {x-1, x+1, 2*x})
		{
			if(nxt<0||nxt>100000||visit[nxt]) continue;
			q.push(nxt);
			visit[nxt] = visit[x] + 1;
		}
	}	
}

//visit 외에 뺄 수 있을 상황
//처음부터 n > k인 경우는 따로 뺄 거라 상관 없음
//도중에 n>k가 된 경우는 무조건 -1만
//그러나 n<k일 때는 뭘 해도 상관 없음
