/*
공백 포함한 문자열 getline
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while(getline(cin, s))
	{
		if(s == ".")	break;
		stack<char> stk;

		for(auto c:s)
		{
			if(c == '(' || c == ')' || c == '[' || c == ']')
			{
				if(!stk.empty())
				{
					char top = stk.top();
					if((top == '(' && c == ')') || top == '[' && c == ']')
					{
						stk.pop();
						continue;
					}
				} 
				stk.push(c);
			}
		}
		if(stk.empty())	cout << "yes\n";
		else	cout << "no\n";
	}
	return 0;
}