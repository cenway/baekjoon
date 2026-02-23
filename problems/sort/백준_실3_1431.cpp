//sort 범위 주의 (s+n O/ s+51 X)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s[51];

bool cmp(const string & a,const string & b)
{
	if(a.length() != b.length())
	{
		if(a.length() > b.length())	return false;
		else return true;
	}

	int suma, sumb;
	suma = 0;
	sumb = 0;
	for(auto c:a)
	{
		if(c>='0'&&c<='9')
			suma += c - '0';
	}
	for(auto c:b)
	{
		if(c>='0'&&c<='9')
			sumb += c - '0';
	}

	if(suma != sumb)
	{
		if(suma > sumb) return false;
		else return true;
	}
	
	return a < b;
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	sort(s, s + n, cmp);

	for(auto ans : s) cout << ans << '\n';

	return 0;
}

/*
비교 순위
1. 짧은 거
2. 숫자 합해서 더 작은 거
3. 사전 순. 숫자가 더 작음 0~9 A~Z
*/