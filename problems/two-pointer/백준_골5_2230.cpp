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

	int j = 0;
	int min_diff = 2000000001;
	for(int i = 0; i < n; i++)
	{
		while((j < n) && arr[i]+m > arr[j]) j++;
		if(j >= n) break;
		if(min_diff > arr[j]-arr[i]) min_diff = arr[j]-arr[i];
	}
	cout << min_diff;
	return 0;
}