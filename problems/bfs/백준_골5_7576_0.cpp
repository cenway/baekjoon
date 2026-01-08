#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


int map[1002][1002];
int arr[700000] = { 0, };
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };

queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(map, -1, sizeof(map));

	int m, n; // map 입력 받기
	int one = 0, zero = 0;//예외처리용
	int day = 0;

	cin >> m >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				one += 1;
				q.push({i,j});
				arr[0] += 1;
			}
			else if (map[i][j] == 0)
				zero += 1;
		}

	}
		
	if (one == 0)//예외 처리?
	{
		cout << -1 << endl;
		return 0;
	}

	else if (zero == 0)
	{
		cout << 0 << endl;
		return 0;
	}


	while (!q.empty())
	{
		pair<int, int> ripe;
		ripe = q.front(); q.pop();
		arr[day] -= 1;


		for (int i = 0; i < 4; i++)
		{
			int ny = ripe.first + y[i];
			int nx = ripe.second + x[i];
			if (map[ny][nx] == 0)
			{
				q.push({ ny,nx });
				arr[day + 1] += 1;
				map[ny][nx] = 1;
			}
		}
		if (arr[day] == 0)
			day += 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << day -1 << endl;
	return 0;
}