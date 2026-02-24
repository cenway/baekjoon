#include <iostream>
#include <algorithm>

using namespace std;

int arra[51];
int arrb[51];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> arra[i];
	for(int i = 0; i < n; i++)
		cin >> arrb[i];

	sort(arra, arra+n);
	sort(arrb, arrb+n);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += arra[i]*arrb[n-i-1];

	cout << ans;
	return 0;
}

//그냥 인덱스 찾기 문제 같은데
//큰 숫자에 작은 숫자 곱해주기