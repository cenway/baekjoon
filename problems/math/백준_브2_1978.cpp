#include <iostream>
#include <vector>

using namespace std;

int arr[101];
bool prime[1001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(max < arr[i]) max = arr[i];
	}

	prime[1] = true;

	for(int i = 2; i*i <= max; i++)
	{
		if(prime[i]) continue;
		for(int j = i*i; j <= max; j += i)
			prime[j] = true;
	}

	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(!prime[arr[i]]) ans++;
	}
	cout << ans;
	return 0;
}