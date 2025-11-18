#include <stdio.h>
#include <math.h>

int main() 
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        double x1, y1, r1, x2, y2, r2;
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
        if(x1 == x2 && y1 == y2)
        {
            if(r1 == r2)
            {
                printf("-1\n");
                continue;
            }
            printf("0\n");
            continue;     
        }
        
        double dist = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        if(dist > r1 && dist > r2)
        {
            if(dist > (r2 + r1))
            {
                printf("0\n");
                continue;
            }
            if(dist < (r2 + r1))
            {
                printf("2\n");
                continue;
            }
            printf("1\n");
            continue;
        }
        double min_r = r1, max_r = r2;
        if(r1 > r2)
        {
            min_r = r2;
            max_r = r1;
        }
        if(dist + min_r > max_r)
        {
            printf("2\n");
            continue;
        }
        if(dist + min_r < max_r)
        {
            printf("0\n");
            continue;
        }
        printf("1\n");
        continue;
            
    }
    return 0;
}

/*
생각 좀 해보자
다양한 케이스가 존재할탠데
1. 원의 중심이 외부일 때
1) 반지름의 합이 중심 간의 거리보다 크다/같다/작다
2. 원의 중심이 다른 원의 내부일 때
1) 중심 간 거리 + 반지름(작은 쪽)이 반지름(큰 쪽)보다 크다/같다/작다
3. 원의 중심이 같다
1) 반지름이 같다/다르다
*/
 
