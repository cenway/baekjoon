/*
빈 리스트를 만들면 .begin() == .end() == 더미노드
insert나 push_back 후 .begin() == 첫 노드, .end() == 여전히 더미노드
더미노드는 무조건 .end()
.begin()은 무조건 첫 노드
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
		string s;
		cin >> s;

		list<char> l;
		auto t = l.begin();

		for(auto c:s)
		{
			if(c == '<')
			{
				if(t != l.begin())	
				{
					t--;
				}
			}
			else if(c == '>')
			{
				if(t != l.end()) t++;
			}
			else if(c == '-')
			{
				if(t != l.begin())
				{
					t--;
					t = l.erase(t);
				}
			}
			else
			{
				l.insert(t, c);
			}
			
					
		}
		for(auto it = l.begin(); it != l.end(); it++)
		{
			cout << *it;
		}
			
		cout << '\n';
		
	}
	return 0;
}