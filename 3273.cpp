#include <bits/stdc++.h>
using namespace std;

int arr1[100000];
int arr2[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	int x;
	cin >> x;

	sort(arr1, arr1 + n);
	for(int i = 0; i < n; i++)
	{
		arr2[n - i - 1] = x - arr1[i];
	}
	int i = 0, j = 0, ans = 0;
	while((i < n) && (j < n))
	{
		if(arr1[i] >= arr2[j])
		{
			if(arr1[i] == arr2[j])
				ans++;
			j++;

		}
		else
			i++;
	}
	cout << ans/2;
	return 0;
}