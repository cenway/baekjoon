#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--)
	{
		stack <char> stk;
		string s;
		cin >> s;
		for(auto c:s)
		{
			if(!stk.empty() && stk.top() == '(' && c == ')')
				stk.pop();
			else stk.push(c);
		}
		if(stk.empty())	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}