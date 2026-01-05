//답을 문자열로 출력할 때는 항상 아스키 변환에 주의
//특히 두자리 수 이상의 경우

#include <bits/stdc++.h>
using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		deque<int> dq;
		bool rflag = false;
		string func, s, ans = "none";
		cin >> func;

		int t;
		cin >> t;

		cin >> s;
		char tmp;
		//문자열로 받은 정수 배열을 정수 덱으로 저장
		for(auto c:s)
		{
			if(c >= '0' && c <= '9')
			{
				int x = c - '0';
				if(tmp >= '0' && tmp <= '9') 
				{
					x += dq.back() * 10;
					dq.pop_back();
				}
				dq.push_back(x);
			}
			tmp = c;
		}
		
		//함수에 따라 정수 덱 정리
		for(auto c:func)
		{
			//dq의 앞에서 할지, 뒤에서 할지
			if(c == 'R')	rflag ^= 1;
			//지우기
			else if(c == 'D')
			{
				if(dq.empty())	
				{
					ans = "error\n";
					break;
				}
				else if(!rflag)	dq.pop_front();
				else if(rflag)	dq.pop_back();
			}
		}
		//답안 출력. 
		if(ans != "error\n")
		{
			ans = "[";
			if(!rflag)
			{
				while(!dq.empty())
				{
					ans += to_string(dq.front());
					ans += ',';
					dq.pop_front();
				}
			}
			else
			{
				while(!dq.empty())
				{
					ans += to_string(dq.back());
					ans += ',';
					dq.pop_back();
				}
			}
			if(ans.back() == ',') ans.pop_back();
			ans += "]\n";
		}
		cout << ans;
	}
	return 0;
}

/*
정수 덱으로 만들어서 각 명령어에 대해 명령을 수행하고 출력
*/