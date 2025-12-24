/*
stl list 기본
초기화 되지 않은 리스트에 .begin() .end() 썼으면
접근하지는 말자
또, 다른 문제도 그럴 수 있지만 리스트는 특히 커서가 중요
머리 속에 커서를 같이 넣어두자.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	
	list<char> l;
	for(auto c:s)
	{
		l.push_back(c);
	}
	auto t = l.end();
	

	int m;
	cin >> m;

	for(int i = 0; i < m; i++)
	{
		char tmp1, tmp2;
		cin >> tmp1;
		switch(tmp1)
		{
			case 'L':
				if(t != l.begin())	t--;
				break;
			case 'D':
				if(t != l.end()) t++;
				break;
			case 'B':
				if(t != l.begin()) t = l.erase(--t);
				break;
			case 'P':
				cin >> tmp2;
				l.insert(t, tmp2);
				break;
			default:
				break;
		}
	}

	
	for(auto it = l.begin(); it != l.end(); it++)
	{
		cout << *it;
	}
	return 0;
}

