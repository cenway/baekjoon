#include <iostream>
#include <unordered_set> 
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

unordered_set<string> s;

bool cmp(const string & a, const string & b)
{
	return a > b;
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--)
	{
		string tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		if(tmp2 == "enter") s.insert(tmp1);
		else s.erase(tmp1);
	}
	vector <string> ans;
	for(auto e : s) ans.push_back(e);
	sort(ans.begin(), ans.end(), cmp);
	for(auto e : ans) cout << e << '\n';	

	return 0;
}