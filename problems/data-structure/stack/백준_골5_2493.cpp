#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	int val;
	int idx;
}p;

stack<p> stk;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	p max = {0, 0};
	int n, nidx = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		nidx++;
		int tmp;
		cin >> tmp;
		if((max.val < tmp) || (max.idx == 0))
		{
			cout << "0 ";
			while(!stk.empty())	stk.pop();
			max.val = tmp;
			max.idx = nidx;
			stk.push(max);
			continue;
		}
		while(stk.top().val < tmp)	stk.pop();
		cout << stk.top().idx << ' ';
		stk.push({tmp, nidx});
	}

	return 0;
}

/*
만날 때까지 다 비교하면
최악의 경우 O(n^2)

스택과 최대값을 활용해서 해보자
최대값보다 크면 걔가 새로운 최대값
작으면 스택에서 빼면서 첫 값을 찾기?
ㄴ스택을 채우는 건 최대값부터
ㄴ뺐던 건? 다시 넣을 필요 있나?
ㄴㄴ뺐다는 건 결국 현재 값보다 작다는 것. 큰 것도 아니고 작은 것을 왜 채움

최대값 확인(보다 크면 0, 스택 비우기)-스택 확인(본인보다 큰 값과 본인은 다시 채워둠)
ㄴ그래서 값과 인덱스를 함께 보관해야 할 거 같음
*/