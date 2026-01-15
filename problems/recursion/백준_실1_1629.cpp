//모듈러 연산 ((a^n)%b)*((a^n)%b) = (a^2n)%b
//그냥 진짜 매 순간 마다 Overflow날 수 있는 문제니
//매번 나눠줘야 함
#include <iostream>
using namespace std;

long long func(long long a, long long b, long long c)
{
	if(b == 0) return 1;
	if(b == 1) return a%c;

	long long val = func(a, b/2, c);
	val = ((val%c)*(val%c))%c*func(a, b%2, c);
	return val%c;
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << func(a, b, c);
	return 0;
}
