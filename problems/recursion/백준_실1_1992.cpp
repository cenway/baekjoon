#include <iostream>
using namespace std;

const int N = 128;

char arr[N][N];

void func(int n, int x, int y)
{
	if(n == 1) 
	{
		cout << arr[x][y];
		return;
	}
	//괄호, 검사 로직, func, 괄호 닫기  
	int nn = n >> 1;

	bool flag = false;
	for(int i = x; i < x + n; i++)
		for(int j = y; j < y + n; j++)
			if(arr[x][y] != arr[i][j])	
				flag = true;

	if(flag) 
	{
		cout << '(';
		func(nn, x, y);
		func(nn, x, y + nn);
		func(nn, x + nn, y);
		func(nn, x + nn, y + nn);
		cout << ')';
	}
	else
		cout << arr[x][y];
	
}

int main() {
	// 코드 작성
	int k;
	cin >> k;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++)
			cin >> arr[i][j];

	func(k, 0, 0);

	return 0;
}
