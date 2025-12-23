#include <bits/stdc++.h>
using namespace std;

int arr[2][7];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, k;
	cin >> N >> k;

	for(int i = 0; i < N; i++)
	{
		int s, g;
		cin >> s >> g;
		arr[s][g] += 1;
	}
	
	int ans = 0;

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			int tmp = 0;
			if(arr[i][j]%k)	tmp = 1;
			ans += arr[i][j]/k + tmp;
		}
	}

	cout << ans;

	return 0;
}