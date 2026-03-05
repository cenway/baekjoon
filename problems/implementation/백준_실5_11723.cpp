#include <iostream>
#include <string>

using namespace std;

unsigned int S;


int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			int tmp;
			cin >> tmp;
			S |= 1 << tmp;
		}
		else if (s == "remove")
		{
			int tmp;
			cin >> tmp;
			S &= ~(1 << tmp);
		}
		else if (s == "check")
		{
			int tmp;
			cin >> tmp;
			cout << !((S & (1 << tmp)) == 0) << '\n';
		}
		else if (s == "toggle")
		{
			int tmp;
			cin >> tmp;
			if(S & (1 << tmp))
				S &= ~(1 << tmp);
			else
				S |= 1 << tmp;
		}
		else if (s == "all")
		{
			S = 0xFFFFFF;
		}
		else if (s == "empty")
		{
			S = 0;
		}
	}
	return 0;
}