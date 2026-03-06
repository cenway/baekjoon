#include <iostream>

using namespace std;

int arr[20000001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while(n--)
	{
		int tmp;
		cin >> tmp;
		arr[tmp + 10000000]++;
	}

	int m;
	cin >> m;
	while(m--)
	{
		int tmp;
		cin >> tmp;
		cout << arr[tmp + 10000000] << ' ';
	}
	return 0;
}