#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num = 1;
	for(int i = 0; i < 3; i++)
	{
		int tmp;
		cin >> tmp;
		num *= tmp;
	}

	while(num != 0)
	{
		arr[num%10] += 1;
		num /= 10;
	}
	
	for(int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}
