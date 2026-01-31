//dfs중 visit을 체크하기 어려운 경우는 재귀가 편한듯
//알고리즘에서는 때려죽어도 endl을 쓰지마
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n;
bool arr[9];
void func(int m, int k)
{
	if(m == 0)
	{
		for(auto i: v)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for(int i = k; i <= n - m + 1; i++)
	{
		if(arr[i]) continue;
		arr[i] = true;
		v.push_back(i);
		func(m-1, i+1);
		v.pop_back();
		arr[i] = false;
	}
}

int main() {
	// 코드 작성
	int m;
	cin >> n >> m;

	func(m, 1);
	return 0;
}