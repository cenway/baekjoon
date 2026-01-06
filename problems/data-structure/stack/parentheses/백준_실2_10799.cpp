#include <bits/stdc++.h>
using namespace std;

#define OPEN '('
#define CLOSE ')'

typedef struct 
{
	int phath;
	int idx;
}p;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0, i = 0;
	stack<p> stk;
	string s;
	cin >> s;
	
	for(auto c:s)
	{
		int phat = (c == '(')? OPEN:CLOSE;

		if(!stk.empty() && stk.top().phath == OPEN && phat == CLOSE)
		{
			if(stk.top().idx + 1 == i)
			{
				//얘가 레이져
				ans += stk.size() - 1;
			}
			else
			{
				//얘가 쇠막대기
				ans++;
			}
			stk.pop();
		}
		else stk.push({phat, i});
		i++;
	}
	cout << ans;
	return 0;
}

/*
인덱스 정보를 추가해서
pop될 때 본인이 레이저인지 쇠막대기인지 확인
근데 스택 사이즈 - 1가 쇠막대기 수 아닌가
그럼 그게 끝인가?
*/