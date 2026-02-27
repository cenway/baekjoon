#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[100001];

typedef struct
{
	int val;
	int bit;
	int min;
	vector<int> dist;
}p;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> arr[i];


	queue<p>q;
	q.push({0, 0, 0, {0, }});
	int max_dist = 0;

	while(!q.empty())
	{
		int nval = q.front().val;
		int nbit = q.front().bit;
		int nmin = q.front().min;
		if((nmin < max_dist) || (nval > n) || (1 << nbit) > n) 
		{
			q.pop();
			continue;
		}

		vector<int> ndist1 = q.front().dist;
		vector<int> ndist0 = q.front().dist;

		q.pop();
		//1비트 추가
		int min_dist = 50;
		for(int i = 0; i < m; i++)
		{
			if(arr[i] & 1 << nbit) 
			{
				ndist1[i]++;
			}
			if(min_dist > ndist1[i]) min_dist = ndist1[i];
		}
		if(max_dist < min_dist) max_dist = min_dist;
		q.push({nval + 1, nbit + 1, min_dist, ndist1});
		
		//0비트 추가
		min_dist = 50;
		for(int i = 0; i < m; i++)
		{
			if(!(arr[i] & 1 << nbit)) 
			{
				ndist0[i]++;
			}
			if(min_dist > ndist0[i]) min_dist = ndist0[i];
		}
		if(max_dist < min_dist) max_dist = min_dist;
		q.push({nval, nbit + 1, min_dist, ndist0});
	}

	cout << max_dist;
	return 0;
}


/*
이번 pwd가 pi로 주어진 숫자면 안 봐도 되고(어차피 안전도 0임)
역전? 되는 경우가 있나
적어도 개별에 대해서는 이전의 결과가 이후에 영향을 주진 않아

역전의 경우가 없다고 가정하고

1씩 더하고, 비트도



*/