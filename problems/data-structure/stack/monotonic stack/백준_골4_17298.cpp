#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	int val;
	int idx;
}p;

stack<p> stk;

int ans[1000000];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	memset(ans, -1, sizeof(ans));

	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		while(!stk.empty() && stk.top().val < tmp)
		{
			ans[stk.top().idx] = tmp;
			stk.pop();
		}
		stk.push({tmp, i});
	}	

	for(int i = 0; i < n; i++)
	{
			cout << ans[i] << ' ';
	}
	return 0;
}

/*
약간 방향이 정해져 있는 경우가 스택 쓰기 좋은 거 같다
계속 push하다가 top보다 큰 값이 나오면 pop 하고 배열에 저장할까
*/