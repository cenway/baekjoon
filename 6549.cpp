#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	long long cnt;
	int height;
}p;

stack<p> stk;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(1)
	{
		cin >> n;
		if(!n)	break;

		long long max = 0;
		while(n--)
		{
			int tmp;
			long long ncnt = 1;
			
			cin >> tmp;

			while(!stk.empty() && stk.top().height > tmp)
			{
				ncnt = stk.top().cnt;
				long long k = stk.top().height * ncnt;
				if(max < k) max = k;
				stk.pop();
				if(!stk.empty())	stk.top().cnt +=ncnt;
			}
			stk.push({ncnt, tmp});
		}
		while(!stk.empty())
			{
				long long ncnt = stk.top().cnt;
				long long k = stk.top().height * ncnt;
				if(max < k) max = k;
				stk.pop();
				if(!stk.empty())	stk.top().cnt +=ncnt;
			}
		cout << max << "\n";
	}
	return 0;
}
/*
값 높이 별 최대 값을 저장해?
그럼 조건을 달아야지
1. 그냥 q로 어디까지 가나  1 2 3 있다카면
1(3) 2(2) 3
ㄴ이거는 시간복잡도 n^2나옴

2.스택으로
위에가 안 끊기면
밑에는 안 끊김

그럼 언제가 끊긴건지 == 작은 값이 들어올 때
위가 끊겼을 때 밑에 뭘 해줘야 할지 == 그 크기를 더해줘야지

최대값은 뺄 때 계산
*/