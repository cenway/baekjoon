#include <iostream>
#include <queue>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		unsigned long long ans = 0;
		int n;
		cin >> n;
		priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;
		for(int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			pq.push(tmp);
		}

		while(pq.size() > 1)
		{
			unsigned long long a, b;
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			ans += a+b;
			pq.push(a+b);
		}
		cout << ans << '\n';
	}
	return 0;
}