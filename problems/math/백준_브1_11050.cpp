#include <iostream>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int ans = 1;
	for(int i = n - k + 1; i <= n; i++)
		ans *= i;
	for(int i = 1; i <= k; i++)
		ans /= i;
	cout << ans;
	return 0;
}