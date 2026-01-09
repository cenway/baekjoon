#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

pair<int, int> arr[100000];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>> stk;

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		arr[i].first = tmp1*32 + tmp2;
		cin >> tmp1 >> tmp2;
		arr[i].second = tmp1*32 + tmp2;
	}
	sort(arr, arr+N);

	int min = 3*32 + 1;
	for(int i = 0; i < N; i++)
	{
		pair<int, int>flw = arr[i];
		if(flw.first <= min && flw.second > min)
		{
			while(!stk.empty())
			{
				//어디까지 빼도 연결(second가 first보다 높나)
				//
				pair<int, int>tmp = stk.top();
				stk.pop();
				if(!stk.empty() && stk.top().second >= flw.first)
					continue;
				//뺴보니 연결이 안 됐거나 스택이 비었거나
				if(flw.first <= 3*32+1)
					break;
				stk.push(tmp);
				break;
			}
			stk.push(flw);
			if(flw.second > 12*32) break;
			min = flw.second;
		}
	}

	//출력 전에 second가 12/1에 도달했는지
	if(!stk.empty() && stk.top().second > 12*32)
		cout << stk.size();
	else	
		cout << 0;
	return 0;
}
