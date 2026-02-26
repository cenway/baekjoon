#include <iostream>
using namespace std;

int arr[301];
int ans[2][301];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> arr[i];

	ans[0][1] = arr[1];
	ans[0][2] = arr[2];
	ans[1][2] = arr[1] + arr[2]; 
	for(int i = 3; i <= n; i++)
	{
		ans[0][i] = max(ans[0][i-2], ans[1][i-2]) + arr[i];
		ans[1][i] = ans[0][i-1] + arr[i];
	}
	cout << max(ans[0][n], ans[1][n]);
	
	return 0;
}

//1. 해당 발판까지 최대값
//2. ans[i] = max(ans[i-1], ans[i-2])+arr[i];
//ㄴ 근데 여기서 3연속은 피해야 되는데
//3. ans[1], ans[2]