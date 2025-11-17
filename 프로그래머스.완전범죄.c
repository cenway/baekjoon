#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int a_min, N, M, limit;
int ** arr;
bool memory[120][120][40];


void dfs(int a, int b, int depth)
{
    if(depth == limit)
    {
        if(a < a_min)
            a_min = a;
    }
    else if(!memory[a][b][depth])
    {
        b += arr[depth][1];
        if(b < M)
            dfs(a, b, depth + 1);
        memory[a][b][depth] = true;
        b -= arr[depth][1];
        
        
        a += arr[depth][0];
        if((a < N) && (a < a_min))
            dfs(a, b, depth + 1);  
        memory[a][b][depth] = true;
    }  
    //결국 시간 오바해버려서 메모이제이션 활용. 근데 메모리만 576kB라는 엄청난 크기를 차이하는데, 이를 절약할 수 있는 방법이 뭐가 있을까?

}

// info_rows는 2차원 배열 info의 행 길이, info_cols는 2차원 배열 info의 열 길이입니다.
int solution(int** info, size_t info_rows, size_t info_cols, int n, int m) {
    int answer = 0, a_max = 0, b_max = 0;
    arr = info;
    N = n;
    M = m;
    limit = info_rows;
    
    for(int i = 0; i < info_rows; i++)
    {
        a_max += info[i][0];
        b_max += info[i][1];
    }
    
    if(b_max < m)
        return answer;
    
    a_min = a_max;
    
    dfs(0, 0, 0);
    if(a_min >= n)
        a_min = -1;
    
    return answer = a_min;
}
/*
처음에 합분해 같은 느낌으로 접근해서 크게 애먹었던 문제
스택을 활용한 이진트리 dfs로 접근하자니 visit을 만들기는 너무 크다고 생각해서 포기하고 제귀로 만들었는데, 결국 시간 초과
어차피 1, 2, 3밖에 없으면 같은 depth에서 같은 a, b 값이 자주 생길 것으로 판단
메모이제이션 결과 크게는 1000배가 넘는 시간 절약이 가능했음
그러나 결국 메모리는 상당히 사용하긴 함
*/
