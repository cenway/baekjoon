#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);

	int m;
	cin >> m;
	while(m--)
	{
		int k;
		cin >> k;
		int high = n-1;
		int low = 0;
		int mid = high/2;
		
		int ans = 0;
		while(high != low)
		{
			if(k == arr[mid]) 
			{
				ans = 1;
				break;
			}
			else if(k < arr[mid])	high = mid - 1;
			else					low = mid + 1;
			mid = (high+low)/2;
		}
		if(k == arr[mid])  ans = 1;
		cout << ans << '\n';
	}
	return 0;
}