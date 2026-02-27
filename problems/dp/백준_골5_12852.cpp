//첫 for문에서 다른 배열에 해당 i 직전 최소인 인덱스를 미리 저장해두면
//나중에 경로 복원이 빠름
#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	for(int i = 4; i <= n; i++)
	{
		arr[i] = arr[i-1] + 1;
		if(i%2 == 0) arr[i] = (arr[i] < arr[i/2] + 1)? arr[i]:arr[i/2]+1;
		if(i%3 == 0) arr[i] = (arr[i] < arr[i/3] + 1)? arr[i]:arr[i/3]+1;
	}
	cout << arr[n] << '\n';
	
	
	while(1)
	{
		int k = n;
		cout << k << ' ';
		if(k == 1) break;
		if(arr[n] > arr[n-1]) k = n-1;
		else if(n%2 == 0 && arr[n] > arr[n/2]) k = n/2;
		else if(n%3 == 0 && arr[n] > arr[n/3]) k = n/3;
		n = k;
	}
	return 0;
}