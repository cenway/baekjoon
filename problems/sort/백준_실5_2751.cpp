//정렬 구현 시 검증용 문제로 활용
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp;
	cin >> n;
	tmp = n;
	while(n--) cin >> arr[n];
	sort(arr, arr+ tmp);
	for(int i = 0; i < tmp; i++)
		cout << arr[i] << '\n';
	return 0;
}