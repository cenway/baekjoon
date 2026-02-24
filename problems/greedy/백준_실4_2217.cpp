#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

bool cmp(const int& a, const int& b)
{
	return a>b;
}
int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin>> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n, cmp);

	int max = 0;

	for(int i = 0; i < n; i++)
	{
		if((i+1)*arr[i] > max)
		{
			max = (i+1)*arr[i];
		}
	}
	cout << max;
	return 0;
}