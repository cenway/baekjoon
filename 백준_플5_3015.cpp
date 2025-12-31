#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	unsigned long long int cnt;
	int height;
}p;

stack<p> stk;
int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	unsigned long long int ans = 0;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		while(!stk.empty())
		{
			if(stk.top().height == tmp)
			{
				ans += stk.top().cnt - 1;
				stk.top().cnt++;
				break;
			}
			else if(stk.top().height < tmp)
			{
				unsigned long long int ncnt = stk.top().cnt;
				ans += (ncnt << 1) - 1;
				stk.pop();
				if(stk.empty())
					ans -= ncnt;
			}
			else
			{
				stk.push({1, tmp});
				break;
			}
		}
		if(stk.empty())
			stk.push({1, tmp});
	}
	while(!stk.empty())
	{
		unsigned long long int ncnt = stk.top().cnt;
		stk.pop();
		if(!stk.empty())
		ans += ncnt - 1;
	}

	cout << ans + n - 1;
	return 0;
}

/*
키가 같은 경우 때문에 애를 많이 먹음
경우의 수가 많은 경우에 이 문제처럼 
고정된 상황과 아닌 상황을 나누는 것도 방법인듯
*/

/*
기본값 n - 1
추가되는 경우
3 2 2 4
3 1 2 2 4
3 1 2 2 1 4
=> 보다 큰 값이 생기면 +1
사이 거 터뜨릴 때
5 1 4 1 3 1 2 1 => 54321
사이 낀 값 처리만 잘 해두고
마지막에 주르르륵
ans += cnt - 1
그럼 10 9 8 9 8 9는?
10 9(3)

1(100)인 경우도


*/