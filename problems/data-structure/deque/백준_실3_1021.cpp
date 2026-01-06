/*
자료구조 정의 상 중간 값을 뒤지는 건 안되는 게 맞음
그 정의를 따르면 deque 안 써도 됨 이 문제는
그런데 STL이 주어준 기능으로 그냥 쓰는겨
find는 반복자를 반환하는데 - 연산으로 int형 값으로 나옴
반복 수가 늘어나면 while{if-else}보단 if{while}-else{while}이 시간 이득
*/
#include <bits/stdc++.h>
using namespace std;

deque <int> dq;
int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)	dq.push_back(i);

	int m, ans = 0;
	cin >> m;

	for(int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;

		int idx = find(dq.begin(), dq.end(), tmp) - dq.begin();
		while(tmp != dq.front())
		{
			if(idx < dq.size() - idx)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ans++;
		}
		dq.pop_front();
	}
	cout << ans;
	return 0;
}
