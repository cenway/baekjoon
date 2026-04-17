//합하고 힙에 다시 집어 넣기
#include <iostream>
#include <queue>
using namespace std;

unsigned long long ncnt;


int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	while(pq.size() > 1)
	{
		unsigned long long a, b, sum;
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		sum = a + b;
		ncnt += sum;
		pq.push(sum);
	}

	cout << ncnt;

	return 0;
}