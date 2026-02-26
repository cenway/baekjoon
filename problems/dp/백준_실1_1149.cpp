#include <iostream>
using namespace std;

int arr[3][1001];
int ans[3][1001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];

	
	ans[0][1] = arr[0][1];
	ans[1][1] = arr[1][1];
	ans[2][1] = arr[2][1];
	
	for(int i = 2; i <= n; i++)
	{
		ans[0][i] = min(ans[1][i-1], ans[2][i-1]) + arr[0][i];
		ans[1][i] = min(ans[0][i-1], ans[2][i-1]) + arr[1][i];
		ans[2][i] = min(ans[1][i-1], ans[0][i-1]) + arr[2][i];
	}

	cout << min(min(ans[0][n], ans[1][n]), ans[2][n]);

	return 0;
}