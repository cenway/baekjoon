#include<bits/stdc++.h>

using namespace std;

bool arr[50][50];
bool visited[50][50];

queue<int> q;
int cnt;

int yy[4] = {1, -1, 0, 0};
int xx[4] = {0, 0, 1, -1};

void bfs()
{
    //현재 좌표에서 상하좌우를 확인 후 인접한 배추가 있으면 
    //있으면 visit에 표시하고 큐에 넣기
    //예외 상황: 배열의 크기를 넘어갈 때
    
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
    
        int y = 0;
        int x = 0;

        if(tmp)
        {
            y = tmp/50;
            x = tmp%50;
        }
        

        for(int i = 0; i < 4; i++)
        {
            int ny = y + yy[i];
            int nx = x + xx[i];
            if((ny < 0) || (ny > 49) || (nx < 0) || (nx > 49))
                continue;

            if((visited[ny][nx] == 0) && (arr[ny][nx] == 1))
            {
                visited[ny][nx] = 1;
                int tmp2 = ny * 50 + nx;
                q.push(tmp2);
            }
                        
        }
    }

}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int m, n, k;
        cin >> m >> n >> k;

        for(int j = 0; j < k; j++)
        {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        //bfs돌리기
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((arr[i][j] == 1) && (visited[i][j] == 0))
                {
                    visited[i][j] = 1;
                    int tmp = i * 50 + j;
                    q.push(tmp);
                    bfs();
                    cnt++;
                }       
            }
        }

        //끝나면 결과 출력 및 결과, arr, visit 초기화(헷갈리면 for문으로)
        cout << cnt << "\n";
        cnt = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        while(!q.empty())   q.pop();
    }


    return 0;
}