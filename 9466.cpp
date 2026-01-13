#include <iostream>
#include <stack>

using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		int arr[100001] = {0, };
		bool pointed[100001] = {0, };
		int visit[100001] = {0, };
		int n;
		int ans = 0;

		cin >> n;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			pointed[arr[i]] = true;
		}
		for(int i = 1; i <= n; i++)
		{
			if(pointed[i]) continue;
			stack<int> stk;

			stk.push(i);
			visit[i] = i;
			
			while(!visit[arr[stk.top()]]) 
			{
				stk.push(arr[stk.top()]);
				visit[arr[stk.top()]] = i;
				cout << stk.top() << endl;
			}
			if(visit[arr[stk.top()]] == visit[stk.top()])
			{
				int tmp = arr[stk.top()];
				while(tmp != stk.top())	
				{
					stk.pop();
					cout << stk.top() << endl;
				}
				stk.pop();
			}
			ans+= stk.size();
			//계속 다음 값을 스택에 채워 넣기
			//넣다가 visit에 걸리면 
			//visit값으로 구분해서 다르면 그냥 사이즈를 더하고
			//다음 값(visit인 값)을 저장 후
			//스택을 빼면서 같아질 때까지
			//같아지면 스택에 남은 사이즈를 더하기
		}
		cout << ans << endl;
	}
	return 0;
}
//스택에 넣다가 끝나면 서클이 있었는지 뺴면서 확인
//서클이 있었으면 나머지 size만 더해주기
//O(2N)이 끝일 거 같은데