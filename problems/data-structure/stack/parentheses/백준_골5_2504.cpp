/*
괄호를 닫아가면서 
(), []이면 +2, +3 해서 합산
(x), [x]이면 *2, *3 해서 합산
다 닫히면 ans에 합산
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	char phath;
	int idx;
	int num;
}p;

int main() 
{
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0, i = 0;
	stack<p> stk;
	string s;
	cin >> s;

	for(auto c:s)
	{
		p tmp = {0, 0, 0};
		if(!stk.empty())	tmp = stk.top();

		if(tmp.phath == '(' && c == ')')
		{
			stk.pop();
			if(tmp.idx + 1 == i) tmp.num += 2;
			else tmp.num *= 2;

			if(!stk.empty()) stk.top().num += tmp.num;
			else ans += tmp.num;
		}
		else if(tmp.phath == '[' && c == ']')
		{
			stk.pop();
			if(tmp.idx + 1 == i) tmp.num += 3;
			else tmp.num *= 3;

			if(!stk.empty()) stk.top().num += tmp.num;
			else ans += tmp.num;
		}
		else
		{
			stk.push({c, i, 0});
		}
		i++;
	}
	if(stk.empty()) cout << ans;
	else cout << '0';

	return 0;
}

