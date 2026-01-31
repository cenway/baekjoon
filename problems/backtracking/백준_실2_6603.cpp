#include <iostream>
using namespace std;

int arr[14];
int ans[7];
int n;

void func(int p, int num)
{
	if(num == 6)
	{
		for(int i = 0; i < 6; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	
	for(int i = p; i < n; i++)
	{
		ans[num] = arr[i];
		func(i+1, num+1);
	}
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(1)
	{
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; i++) cin >> arr[i];
		func(0, 0);
		cout << '\n';
	}
	return 0;
}