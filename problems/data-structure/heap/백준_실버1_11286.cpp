#include <iostream>
#include <queue>

using namespace std;

class cmp {
public:
	bool operator() (int a, int b) {
		if(abs(a) != abs(b)) return abs(a) > abs(b);
		return a > b;
	}
};


int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, cmp> pq;
	while(n--)
	{
		int x;
		cin >> x;
		if(x == 0)
		{
			if(pq.empty()) 
			{
				cout << "0\n";
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
		{
			pq.push(x);
		}
	}
	return 0;
}