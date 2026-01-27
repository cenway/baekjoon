#include <iostream>
#include <vector>
using namespace std;

bool arrrow[16];
bool arrcross1[31];//차
bool arrcross2[31];//합
int n, ans;

void func(int col)
{
	if(col == n+1)
	{
		ans++;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		//행 마다 하나씩
		//대각선 하나는 둘의 차로, 하나는 둘의 합으로 가능할 듯
		if(arrrow[i] || arrcross1[col - i + n] || arrcross2[col + i])
			continue;
		arrrow[i] = true;
		arrcross1[col - i + n]= true;
		arrcross2[col + i] = true;
		func(col + 1);
		arrrow[i] = false;
		arrcross1[col - i + n]= false;
		arrcross2[col + i] = false;
	}


}
int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(1);
	cout << ans;
	return 0;
}

//재귀도 될 거 같고
//스택도 될 거 같고
//뭐가 됐든 일단 깔고 검사하고 빼고 끝에 도달하면 ans+1

//N*N사이즈에 N개가 들어가야 하므로 각 열/행마다 하나씩 들어가야 함
//대각은 어떻게?
//x,y의 합과 차로