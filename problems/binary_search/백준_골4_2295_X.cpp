//풀리긴 풀렸는데 n^3logn
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr+n);
	
	int k, z, y;
	for(int i = n-1; i >= 0; i--)
	{
		k = i;
		for(int j = i-1; j >= 0; j--)
		{
			z = j;
			for(int l = j; l >= 0; l--)
			{
				y = l;
				if(arr[k]-arr[z]-arr[y]<=0) continue;
				if(binary_search(arr, arr+n, arr[k]-arr[z]-arr[y]))
				{
					cout << arr[k];
					return 0;
				}
			}
		}
	}
	return 0;
}
//이분탐색
//n(k) * n(z) * 