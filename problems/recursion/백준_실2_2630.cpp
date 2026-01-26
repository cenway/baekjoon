#include <iostream>
using namespace std;

const int N = 128;

int arr[N][N];
int ans[2];
int func(int n, int x, int y)
{
	//base
	//n== ?일 때는 return?
	if(n == 1)	
	{
		ans[arr[x][y]]++;
		return arr[x][y];
	}

	//
	int nn = n>>1;
	int tmp = arr[x][y];
	bool flag = false;
	for(int i : {0, nn})
		for(int j: {0, nn})
			if(tmp != func(nn, x+i, y+j)) flag = true;
	if(!flag)
		ans[arr[x][y]] -= 3;
	else
		tmp = 9;
	return tmp;
}

int main() {
	// 코드 작성
	int k;
	cin >> k;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++)
			cin >> arr[i][j];

	func(k, 0, 0);

	cout << ans[0] << endl;
	cout << ans[1] << endl;
	return 0;
}

/*

*/