#include <stdio.h>

int arr[201][201];

int main() 
{
	int N, k;
	scanf("%d %d", &N, &k);

	for(int j = 0; j <= N; j++) 
		arr[1][j] = 1;


	for(int i = 2; i <= k; i++)
	{
		for(int j = 0; j <= N; j++)
		{
			if(j == 0) 
			{
				arr[i][j] = 1;
				continue;
			}
			if((arr[i][j] = arr[i][j - 1] + arr[i - 1][j]) > 1000000000)
				arr[i][j] -= 1000000000;

		}
	}
	printf("%d", arr[k][N]);
	return 0;
}
