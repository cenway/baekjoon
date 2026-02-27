#include <iostream>
using namespace std;

pair<int, int> arr[41];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	arr[0] = {1, 0};
	arr[1] = {0, 1};
	arr[2] = {1, 1};
	arr[3] = {1, 2};

	for(int i = 4; i <= 40; i++)
	{
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}

	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;

		cout << arr[k].first << ' ' << arr[k].second << '\n';
	}

	return 0;
}