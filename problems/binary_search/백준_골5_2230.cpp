#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);

	int min_diff = 2000000001;
	for(int i = 0; i < n; i++)
	{
		long long int tmp = arr[i] + m;
		int diff = 2000000001;
		auto idx = lower_bound(arr+i, arr+n, tmp)-arr;
		if(idx < n)
			diff = arr[idx] - arr[i];
		if(min_diff > diff) min_diff = diff;
	}
	cout << min_diff;
	return 0;
}