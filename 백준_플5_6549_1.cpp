/*
1. 오버플로우 조심(계산 전에 형변환)
2. 방향이 있다 싶으면 스택을 생각해보는데, 
뭐를 넣어야 할지 모르겠다면 dfs
3. 이전 방식에서 인덱스를 사용하는 방식으로 바꿔 로직 최적화
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct

{
	int idx;	
	int height;
}p;

int main() {

	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	while(1)
    {
        cin >> n;
		if(!n)	break;

		stack<p> stk;
		long long max_area = 0;

        for(int i = 0; i < n; i++)
        {
            int tmp;
            int nidx = i;
			cin >> tmp;

            while(!stk.empty() && stk.top().height > tmp)
			{
                int width = i - stk.top().idx;
                long long k = (long long)stk.top().height*width;
                max_area = max(max_area, k);

                nidx = stk.top().idx;
                stk.pop();
            }
            stk.push({nidx, tmp});
        }
        while(!stk.empty())
        {
            int width = n - stk.top().idx;
            long long k = (long long)stk.top().height*width;
            max_area = max(max_area, k);
            stk.pop();
        }
        cout << max_area << '\n';
    }
    return 0;
}