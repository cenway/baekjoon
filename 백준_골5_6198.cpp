#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	int val;
	int num;
}p;

stack<p> stk;


int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long int tmp, ans = 0;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int next;
		cin >> next;

		while((!stk.empty()) && (next >= stk.top().val))
		{
			ans += stk.top().num;
			tmp = stk.top().num;
			stk.pop();
			if(!stk.empty())
			{
				stk.top().num += tmp + 1;
			}
				
			tmp = 0;
		}
		stk.push({next, 0});
	}
	while(!stk.empty())
	{
		ans += stk.top().num;
		tmp = stk.top().num;
		stk.pop();
		if(!stk.empty())
			stk.top().num += tmp + 1;
		tmp = 0;
	}
	
	cout << ans;
	return 0;
}
/*
정말 가장 쉬운 방법은 
1이 어디까지 볼 수 있나 체크
2가 어디까지 볼 수 있나 체크
이럼 최악의 경우 O(n^2)

top보다 큰 값이 들어오면 pop하면서 ans에 +num 뒤에는 +(num+1)
값이 너무 커져서 long long으로 선언해야 함
*/