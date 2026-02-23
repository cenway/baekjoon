#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		arr[i] = {tmp1, tmp2};
	}
	sort(arr, arr+n);

	int pre_end = -1;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(pre_end > arr[i].second) 
		{
			pre_end = arr[i].second;
			continue;
		}

		pre_end = arr[i].second;
		ans++;
	}
	cout << ans;
	return 0;
}

//다 받고 정렬 
//시작 시간이 끝 시간이랑 겹치는 경우, 시작하자마자 끝나는 경우 주의
//pre_begin은 늦지만 더 욱여넣을 수 있는 경우는 pre_end보다 짧은 경우
//begin이 같지만 추가할 경우는 begin이랑 end랑 같은 경우만