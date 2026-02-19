#include <iostream>
using namespace std;

int arrA[1000001];
int arrB[1000001];
int arrC[2000002];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> arrA[i];
	for(int i = 0; i < m; i++)
		cin >> arrB[i];

	int i = 0;
	int j = 0;
	for(int k = 0; k < i+j; k++)
	{
		int big = 0;
		int *tmp = &i;
		
		if(arrA[i] > arrB[j])
		{
			big = arrA[i];
		}
		else
		{
			big = arrB[i];
			tmp = &j;
		}
		arrC[k] = big;
		*tmp += 1;

	}
	return 0;
}