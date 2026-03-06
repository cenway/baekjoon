#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>uni;
int arr[1000001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) 
	{
		cin >> arr[i];
		uni.push_back(arr[i]);
	}

	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	for(int i = 0; i < n; i++)
	{
		cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin()<< ' ';
	}

	return 0;
}