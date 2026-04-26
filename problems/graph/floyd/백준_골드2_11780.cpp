#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int dist[101][101];
int path[101][101];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		fill(dist[i], dist[i]+n+1, INF);
		dist[i][i] = 0;
	}

	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(dist[a][b] > c) dist[a][b] = c;
		path[a][b] = b;
	}

	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(dist[i][j] <= dist[i][k] + dist[k][j]) continue;
				dist[i][j] = dist[i][k] + dist[k][j];
				path[i][j] = path[i][k];
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(dist[i][j] == 0 || dist[i][j] == INF)
			{
				cout << "0\n";
				continue;
			}

			int ans[101];
			int idx = 2;
			int x = i;
			ans[1] = x;
			while(path[x][j] != j)
			{
				x = path[x][j];
				ans[idx] = x;
				idx++;
			}

			ans[idx] = j;
			cout << idx << ' ';
			for(int k = 1; k <= idx; k++) 
				cout << ans[k] << ' ';
			cout << '\n';
		}
	}


	return 0;
}