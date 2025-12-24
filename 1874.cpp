#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string ans = "";
	stack<int> stk;
	for(int i = 1; i <= n; i++)
	{
		if((!stk.empty()) && (stk.top() == k))
		{
			while(stk.top() != k)
			{
				stk.pop();
				cin >> k;
				ans += "-\n";
				if(stk.empty())
					break;
			}

		}
		else if()
		{

		}
	}
	return 0;
}
/*
empty가 아닐 때, 입력값과 비교 후 맞으면 pop
다음 값과 top이 같으면 또 pop
가 끝났는데 입력값이 현재 들어갈 i보다 작으면

*/