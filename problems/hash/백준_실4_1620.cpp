#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;
string arr[100001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		map[tmp] = i;
		arr[i] = tmp;
	}
	while(m--)
	{
		string tmp;
		cin >> tmp;
		if('0' <= tmp[0] && tmp[0] <= '9')
			cout << arr[stoi(tmp)] << '\n';
		else
			cout << map[tmp] << '\n';
	} 
	return 0;
}