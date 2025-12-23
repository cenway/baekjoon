#include <stdio.h>
#include <string.h>


int main() {
	
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		char tmp[1001] = {0, };
		int arr1[26] = {0,};
		int arr2[26] = {0,};
		scanf("%s", tmp);
		char *ptmp = tmp;
		while(*ptmp != 0)
		{
			arr1[*ptmp - 'a'] += 1;
			ptmp++;
		}

		memset(tmp, 0, sizeof(tmp));
		scanf("%s", tmp);

		ptmp = tmp;
		while(*ptmp != 0)
		{
			arr2[*ptmp - 'a'] += 1;
			ptmp++;
		}

		for(int j = 0; j < 26; j++)
		{
			if(arr1[j] != arr2[j])
			{
				printf("Impossible\n");
				break;
			}
			else if(j == 25)
				printf("Possible\n");
		}
		char c;
		scanf("%c", &c);
	}
	return 0;
}

//문자 개수만 맞으면 가능함
//최적화를 위해선 처음엔 +, 섞은 뒤엔 -하면 배열 하나로 가능