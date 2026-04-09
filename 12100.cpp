#include <iostream>
#include <string.h>

using namespace std;

int map[21][21];
int ans;
int n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void func(int pmap[21][21], int cnt)
{
	//방향에 따라서 합치고
	//현재 맵을 넘겨주고, 몇 번째인지 알려주고, 방향? 알려줘야지
	//최대값 비교해서 ans 채우기
	if(cnt >= 5) return;

	for(int i = 0; i < 4; i++)
	{
		int nmap[21][21];
		memset(nmap, 0, sizeof(nmap));
		memcpy(nmap, map, sizeof(nmap));
		//동작 함수
		//가려는 방향에서부터 시작해서
		//
		if(nmap[][])
		{
			if(nmap[][cur] == nmap[][] && cur != ) nmap[][cur] = nmap[][cur] << 1;
			if(!nmap[][cur]) continue;
			cur++;
		}
		

		func(nmap, cnt + 1);
	}
}


int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	int nmap[21][21];
	memset(nmap, 0, sizeof(nmap));
	memcpy(nmap, map, sizeof(nmap));
	func(nmap, 0);

	cout << ans;

	return 0;
}

/*
가려는 방향 우선
최대 5번 이므로 그냥 브루트포스?
4^5

*/