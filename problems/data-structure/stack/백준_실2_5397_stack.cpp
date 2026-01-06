/*
기존 연결 리스트와 커서(반복자)의 위치 변경으로 풀었던 문제를
배열(벡터, 스택도 가능함)로 최적화 함
리스트 자체의 공간 절약과 
오버헤드, 캐시 지역성에 따른 시간 절약
복잡도는 사실 둘다 O(n)
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		vector<char> sl;
		vector<char> sr;

		string s;
		cin >> s;
		for(auto c:s)
		{
			if(c == '<')
			{
				if(!sl.empty())
				{
					char tmp = sl.back();
					sl.pop_back();
					sr.push_back(tmp);
				}
			}
			else if(c == '>')
			{
				if(!sr.empty())
				{
					char tmp = sr.back();
					sr.pop_back();
					sl.push_back(tmp);
				}				
			}
			else if(c == '-')
			{
				if(!sl.empty())
				{
					sl.pop_back();
				}
			}
			else
			{
				sl.push_back(c);
			}
		}
		string ans = "";
		for(auto c:sl)	ans += c;
		reverse(sr.begin(), sr.end());
		for(auto c:sr)	ans += c;
		cout << ans << "\n";
	}
	
	

	return 0;
}