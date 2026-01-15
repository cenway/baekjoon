#include <iostream>
using namespace std;

int r, c;
int cnt;

void func(int n, int x, int y)
{
	//n == 0일 때 자기 칸 확인
	if(!n)
	{
		if(r == x && c == y)
		{
			cout << cnt;
			exit(0);
		}
		cnt++;
		return;
	}
	// n > 1일 때 4등분해서 시작점
	//범위 안에 있는지 확인
	if(x<=r&&r<(x+(1 << (n-1))) && y<=c&&c<y+ (1 << (n-1)))
		func(n-1, x, y);
	if(x+(1 << (n-1))<=r&&r<x+(1 << n) && y<=c&&c<y+ (1 << (n-1)))
	{
		cnt += (1 << 2*(n-1));
		func(n-1, x + (1 << (n-1)), y);
	}
	if(x<=r&&r<x+(1 << (n-1)) && y+(1 << (n-1))<=c&&c<y+ (1 << n))
	{
		cnt += (2*(1 << 2*(n-1)));
		func(n-1, x, y+ (1 << (n-1)));
	}
	if(x+(1 << (n-1))<=r&&r<x+(1 << n) && y+(1 << (n-1))<=c&&c<y+ (1 << n))
	{
		cnt += (3*(1 << 2*(n-1)));
		func(n-1, x + (1 << (n-1)), y+ (1 << (n-1)));
	}
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int n;
	cin >> n >> c >> r;
	func(n, 0, 0);

	return 0;
}