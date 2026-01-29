#include <iostream>
using namespace std;

int arr[21];
int n, s, tmp, ans;
void func(int p)
{
	if(p == n)return;
	
	for(int i = p; i < n; i++)
	{
		tmp += arr[i];
		if(tmp == s){
			ans++;
		}	
		func(i+1);
		tmp -= arr[i];
	}
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	
	for(int i = 0; i < n; i++) cin >> arr[i];
	func(0);
	cout << ans;
	return 0;
}

