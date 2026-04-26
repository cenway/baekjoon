#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 200001;
int dist[101][101];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	for(int i = 1; i <= v; i++)
	{
		fill(dist[i], dist[i]+v+1, INF);
		dist[i][i] = 0;
	}
	
		
	while(e--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for(int i = 1; i <=v; i++)
	{
		for(int j = 1; j <= v; j++)
		{
			for(int k = 1; k <= v; k++)
			{
				dist[j][k] = 
					min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	for(int i = 1; i <= v; i++)
	{
		for(int j = 1; j <= v; j++)
		{
			if(dist[i][j] != INF)
				cout << dist[i][j] << ' ';
			else
				cout << "0 ";
		}
		cout << '\n';
	}
	return 0;
}