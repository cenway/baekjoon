#include <iostream>
using namespace std;

int arr[100001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];

	int min_len = 100002;
	int j = 0;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		while(j <= n && sum < m)
		{
			sum += arr[j];
			j++;
		}
		if(min_len > (j-i) && sum >= m) min_len = (j-i);
		if(j>n) break;
		sum -= arr[i];
	}
	if(min_len == 100002) min_len = 0;
	cout << min_len;
	return 0;
}