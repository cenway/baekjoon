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
		stk.push(i);
		ans += "+\n";
		
		while(!stk.empty() && stk.top() == k)
		{
			stk.pop();
			cin >> k;
			ans += "-\n";
		}
		if((!stk.empty()) && (stk.top() != k) && (stk.top() > k))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << ans;
	return 0;
}
/*
스택 자료구조로 만들 수 있으면 그 순서를,

만들 수 없음이 판단되면 <- 어떻게?
NO를 출력

1. 실제 스택으로 돌리면서 문자열에 저장하다 
스택으로 동작: n기준, 수열 기준
못 만듦: 논리적으로 안 나옴, n이 끝났는데 수열이 남음, 수열이 남았는데 n이 끝남
논리적으로 안 나오는 경우
낮아지는 중인데 수열과 스택top이 다름 {5, 4, 3}인데 5, 3을 요구

*/