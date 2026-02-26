//1차원 배열로 푸는 법
//밟지 않은 계단으로 계산
//왜 i도 밟지 않는 대상이 되어야 하나면, 그래야 연속 3계단 회피 여부를 판단하기 쉬움
//답은 또 구하는 방식이 조금 다름. dp는 작은 것들을 모아서 결과를 얻는 것일 뿐,
//작은 것에 적용한 방식 그대로 답까지 구해야 하는 건 아님
#include <iostream>
using namespace std;

int arr[302];
int unstep[302];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
		ans += arr[i];
	}

	unstep[1] = arr[1];
	unstep[2] = arr[2];
	unstep[3] = arr[3];

	for(int i = 4; i < n; i++)
	{
		unstep[i] = min(unstep[i-2], unstep[i-3]) + arr[i];
	}
	cout << ans - min(unstep[n-1], unstep[n-2]);

	return 0;
}