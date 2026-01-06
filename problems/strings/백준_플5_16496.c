#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void*, const void*);

char arr[1000][11];
char *heap[1000];

int main() 
{
    int N, k = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", arr[i]);
        heap[i] = arr[i];
        if(*arr[i] == '0')
            k++;
    }
    if(k == N)
    {
        printf("0");
        return 0;
    }

    qsort((void *)heap, (size_t)N, sizeof(char *), compare);

    for(int i = 0; i < N; i++)
    {
        printf("%s", heap[i]);
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    char tmp1[21], tmp2[21];
    char *front = *(char **)a;
    char *back = *(char **)b;
    int n1 = strlen(front), n2 = strlen(back);
    //어차피 char은 1byte니 sizeof(front)도 가능
    memcpy(tmp1, front, n1);
    tmp1[n1] = '\0';
    memcpy(tmp2, back, n2);
    tmp2[n2] = '\0';
    strcat(tmp1, back);
    strcat(tmp2, front);

    return strcmp(tmp2, tmp1);
}
