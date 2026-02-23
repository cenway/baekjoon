//카운팅 소트
#include <iostream>
using namespace std;

int arr[2000001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) 
	{
		int j;
		cin >> j;
		arr[j+1000000]++;
	}
	for(int i = -1000000; i < 1000001; i++)
		while(arr[i+1000000]--) cout << i << '\n';
	
	return 0;
}