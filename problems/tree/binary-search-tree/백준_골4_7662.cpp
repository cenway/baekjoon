#include <iostream>
#include <set>

using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--)
	{
		multiset<int> s;
		int k;
		cin >> k;
		while(k--)
		{
			char op;
			int data;
			cin >> op >> data;
			if(op == 'I')
				s.insert(data);
			else if(op == 'D')
			{
				if(s.empty()) continue;
				
				if(data == -1)
					s.erase(s.begin());
				else
					s.erase(prev(s.end()));
			}
			
		}
		if(s.empty())
		{
			cout << "EMPTY\n";
			continue;
		}
		cout << *prev(s.end()) << " " << *s.begin() << "\n";
	}

	return 0;
}