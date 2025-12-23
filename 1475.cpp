#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int num, max;
	cin >> num;

	while(num != 0)
	{
		arr[num%10] += 1;
		num /= 10;
	}

	max = 0;

	for(int i = 0; i < 10; i++)
	{
		if((i == 6) || (i == 9))
			continue;
		
		if(max < arr[i])
			max = arr[i];
	}

	int tmp = arr[6] + arr[9];
	if(max + max < tmp)
		max = (tmp + 1)/2;

	cout << max;

	return 0;
}