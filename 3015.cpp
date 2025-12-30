#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
	int height;
	long long int num;
}p;

stack <p> stk;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long int ans = 0;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		while(!stk.empty() && stk.top().height < tmp)
		{
			long long int nnum = stk.top().num + 1;
			stk.pop();
			ans += nnum;
			
		}
		stk.push({tmp, 0});
	}
	
	cout << ans - 1;
	return 0;
}

/*
더 큰 놈이 나오면 어차피 뒤는 못 본다. 일단 + 1 하고 pop
따라서 이전 사람과의 쌍을 찾아내야 함. 
근데 내 뒤에 놈이 나보다 크면. 걔가 끝이여
걔한테 +1
같으면? 
큰같같중
3+2+1

*/