//dfs중 visit을 체크하기 어려운 경우는 재귀가 편한듯
#include <iostream>
using namespace std;

string s;
int n;
bool arr[9];
void func(int m)
{
	if(m == 0)
	{
		for(auto c: s)
			cout << c << ' ';
		cout << endl;
		return;
	}

	for(int i = 1; i <= n; i++)
	{
		if(arr[i]) continue;
		arr[i] = true;
		

	}

}

int main() {
	// 코드 작성
	int m;
	cin >> n >> m;

	func(m);
	return 0;
}