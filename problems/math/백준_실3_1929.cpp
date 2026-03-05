#include <iostream>
#include <vector>

using namespace std;

bool prime[1000001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	prime[1] = true;

	for(int i = 2; i*i <= m; i++)
	{
		if(prime[i]) continue;
		for(int j = i*i; j <= m; j += i)
			prime[j] = true;
	}
	for(int i = n; i <= m; i++)
		if(!prime[i]) cout << i << '\n';
	return 0;
}