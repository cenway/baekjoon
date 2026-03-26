#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[125251];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n*(n+1)/2; i++)
		cin >> arr[i];

	vector<int> v[n+1];
	v[1].push_back(0);
	v[1].push_back(arr[1]);
	v[1].push_back(0);
	
	for(int i = 2; i <= n; i++)
	{	
		v[i].push_back(0);
		for(int j = i*(i-1)/2+1; j <= i*(i+1)/2; j++)
		{
			v[i].push_back(max(v[i-1][v[i].size()-1], v[i-1][v[i].size()])+arr[j]);
		}
		v[i].push_back(0);
	}
	
	cout << *max_element(v[n].begin(), v[n].end());
	return 0;
}