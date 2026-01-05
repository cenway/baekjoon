/*
시간 초과 떴음
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	int val;
	int idx;
}p;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	deque<p> dq;

	for(int i = 0; i < n; i++)
	{
		int tmp, min = 0, min_idx = 0;
		cin >> tmp;
		dq.push_back({tmp, i});
		if(dq.size() > l)	dq.pop_front();

		//최소값과 그 인덱스를 저장. 
		if(min > dq.back().val)
		{
			min = dq.back().val;
			min_idx = dq.back().idx;
		}
		//최소값이 사라졌는지 확인, 음수 인덱스 잘 거르고
		if(i - l - 1 > min_idx)
		{
			min = 
		}

		cout << min << ' ';
	}

	return 0;
}
/*
시간 초과가 min_element에서 발생했을 거 같음
push와 pop은 O(1)이니까
그냥 mim_element로 구하려면
O(NL)이 된다. 둘 다 변수기 때문 5백만*5백만이 최대
그러면 어찌해야 하는가
적어도 변수 하나를 줄일 수 있거나
최대한 중복되는 경우를 줄이기. 아예 알고리즘 자체를 바꿔?

어떻게 해야 계산량을 줄일 수 있을까
움직이는 윈도우에서
인덱스까지 함께 저장하고 최소값의 인덱스를 기억
ㄴ최소값 pop되면 다음 최소값 찾기

*/