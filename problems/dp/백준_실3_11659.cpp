//미리 합을 구해놓기
#include <iostream>
using namespace std;

int arr[100001];
int S[100001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	S[1] = arr[1];
	for(int i = 2; i <=n; i++) S[i] = S[i-1] + arr[i];

	for(int k = 0; k < m; k++)
	{
		int i, j;
		cin >> i >> j;
		cout << S[j] - S[i] + arr[i] << '\n';
	}
	return 0;
}