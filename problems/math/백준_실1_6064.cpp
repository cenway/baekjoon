#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while(n--)
	{
		int N, M, x, y, a, b;
		cin >> N >> M >> x >> y;
		a = N;
		b = M;
		if(N < M) swap(a, b);
		int last = N/gcd(a, b)*M;
		vector<int>v;
		for(int i = x; i <= last; i += N)
			v.push_back(i);
		
		int ans = -1;

		for(int i = 0; i < v.size(); i++)
		{
			int tmp = v[i]%M;
			if(!tmp) tmp = M;
			if(tmp == y) 
			{
				ans = v[i];
				break;
			} 
		}
		cout << ans << '\n';
	}


	return 0;
}
