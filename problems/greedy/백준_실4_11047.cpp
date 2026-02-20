#include <iostream>
using namespace std;

int arr[10];

int main() {
	// 코드 작성
	int n, tmp, k;
	int cnt = 0;
	cin >> n >> k;
	tmp = n;
	while(tmp--) cin >> arr[tmp];
	for(int i = 0; i < n; i++)
	{
		if(k/arr[i] == 0) continue;
		cnt += k/arr[i];
		k = k%arr[i];
	}
	cout << cnt;

	return 0;
}

//위에서부터 넣고 안되면 내려오기(배수 조건이 달렸으므로 가능)
