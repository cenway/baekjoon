#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)	q.push(i);
	while(q.size() > 1)
	{
		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.front();
	return 0;
}