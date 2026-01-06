#include <bits/stdc++.h>

using namespace std;

typedef struct

{
	long long cnt;	
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

				if(stk.empty() || stk.top().height < tmp) 
					ncnt++;
				else
                {
                    stk.top().cnt += ncnt;
                    ncnt=1;
                }
			}
			if(tmp)
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