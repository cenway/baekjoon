/*
시간 초과 떴었음
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, min_val = 1000000000, min_idx = 0;
	cin >> n >> l;

	deque<pair<int, int>> dq;
	
	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		
		while(!dq.empty() && dq.back().first > tmp)	dq.pop_back();
		dq.push_back({tmp, i});
		if(dq.size() > l || dq.front().second < i - l + 1)	dq.pop_front(); 

		cout << dq.front().first << ' ';
	}

	return 0;
}
/*
가장 쉬운 방법으로 윈도우를 한 칸 옮기고 최소값 확인
N만큼 가는데 매번 L만큼 확인해
O(N*L)이라 시간 초과
그래서 최소값만 확인하는 식으로 바꿨는데
여전히 오름차순의 경우 최악으로 O(N*L) 시간 초과
최소값이 정해지면 그 앞에 나온 값들은 모두 쓸모 없으니 pop해서
min탐색 시간 단축
그럼에도 오름차순은 해결 안 됨. 결국 최소값을 찾는 방식 자체가
O(1)이 되어야 함

========================================================
가장 중요했던 아이디어는 절대 답이 될 수 없는 값이 무었인가

*/