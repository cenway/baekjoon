#include <iostream>
#include <queue>
#include <algorithm>

typedef struct
{
    int X;
    int Y;
    int H;
}tomato;

using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

int board[100][100][100]; // [세로][가로][높이] 순서로 씀
int dist[100][100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tomato>q;

    int n, m, h;
    cin >> m >> n >> h; // [수정] 문제 순서 M(가로), N(세로), H(높이)

    // [수정] 반복문 순서 변경: 높이(k) -> 세로(i) -> 가로(j)
    for(int k = 0; k < h; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1)
                {
                    dist[i][j][k] = 1;
                    q.push({i, j, k});
                }
            }
        }
    }

    int max_dist = 0;
    while(!q.empty())
    {
        int x = q.front().X;
        int y = q.front().Y;
        int h_curr = q.front().H; // 변수명 h와 겹쳐서 h_curr로 표기 (내부 로직 동일)
        q.pop();
        
        if(max_dist < dist[x][y][h_curr]) max_dist = dist[x][y][h_curr];
        
        for(int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nh = h_curr + dh[i];
            
            // [수정] 범위 체크: nx는 세로(n), ny는 가로(m)
            if(nx<0||ny<0||nh<0||nx>=n||ny>=m||nh>=h)
                continue;
            if(dist[nx][ny][nh] || board[nx][ny][nh])
                continue;
            
            q.push({nx,ny,nh});
            dist[nx][ny][nh] = dist[x][y][h_curr] + 1;
            board[nx][ny][nh] = 1;
        }
    }

    // [수정] 반복문 순서 변경: 높이(k) -> 세로(i) -> 가로(j)
    for(int k = 0; k < h; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!board[i][j][k])
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << max_dist - 1;
    return 0;
}