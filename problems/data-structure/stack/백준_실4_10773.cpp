#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> stk;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if(tmp == 0)
		{
			stk.pop();
		}
		else
		{
			stk.push(tmp);
		}
	}

	int ans = 0;
	while(!stk.empty())
	{
		ans += stk.top();
		stk.pop();
	}
	cout << ans;
	return 0;
}