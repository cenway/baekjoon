#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000002];
long long int sum[1000002];

bool cmp(const int & a, const int & b)
{
	return a > b;
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr+1, arr+n+1, cmp);

	sum[1] = 0;
	long long int idx, ans, ans_sum;
	

	for(int i = 2; i <= n+1; i++)
	{
		sum[i] = sum[i-1] + (long long int)(arr[i - 1] - arr[i])*(i-1);
		if(sum[i] >= m) 
		{
			idx = i;
			ans = arr[i];
			ans_sum = sum[i];
			break;
		}
	}

	ans +=(ans_sum - m)/(idx-1);

	cout << ans;
	return 0;
}
//넘치는 경우에 줄이는 건 생각했는데 반대로는 생각 안 했네
//1. 내려가다가 중간에 m을 초과하거나 같아지는 경우
//2. 내려가다가 m미만인데 끝에 도달한 경우
//3. 모든 나무가 높이가 같은 경우
//4. 