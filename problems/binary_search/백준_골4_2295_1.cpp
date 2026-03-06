//미리 합을 구해두는 방식은 다른 알고리즘에도 자주 나오니까 의식했으면 좋겠다.
//이 경우 n^3logn -> n^2logn으로 줄이기 위해 합(n^2)을 미리 구함
//이런 식으로 시간복잡도의 곱을 합으로 치환하는
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int sum_arr[1000001];
int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr+n);
	for(int i = 0; i < n; i++)
	{
		int tmp = i*n;
		for(int j = 0; j < n; j++)
		{
			sum_arr[tmp+j] = arr[i]+arr[j];
		}
	}
	sort(sum_arr, sum_arr+n*n);
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = i-1; j >=0; j--)
		{
			if(arr[i]-arr[j] <= 0) continue;
			if(binary_search(sum_arr, sum_arr+n*n, arr[i]-arr[j]))
			{
				cout << arr[i];
				return 0;
			}
		}
	}
	return 0;
}