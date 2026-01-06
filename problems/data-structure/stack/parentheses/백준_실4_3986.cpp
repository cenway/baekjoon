/*
공백 포함한 문자열 getline
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	while(n--)
	{
		stack<char> stk;
		string s;
		cin >> s;
		
		for(auto c:s)
		{
			if(!stk.empty() && stk.top() == c) stk.pop();
			else stk.push(c);
		}
		if(stk.empty())	ans++;
	}
	cout << ans;
	return 0;
}