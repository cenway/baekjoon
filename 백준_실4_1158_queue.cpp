/*
출력을 문자열로 할 때는 변환 유념할 것.
가능하면 그냥 to_string()하든가 아니면 바로 출력하자
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int n, k;
	string s = "<";
	cin >> n;

	for(int i = 1; i <= n; i++)	q.push(i);

	cin >> k;
	while(!q.empty())
	{
		for(int i = 0; i < k - 1; i++)
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		int tmp = q.front();
		q.pop();
		s += to_string(tmp);
		s += ", ";
	}
	s.pop_back();
	s.pop_back();
	s += '>';
	cout << s;

	return 0;
}