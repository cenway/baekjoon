#include <iostream>
#include <string.h>


using namespace std;

int n;
int ans;


void func(int pmap[21][21], int cnt)
{
	if(cnt >= 5) 
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(ans < pmap[i][j]) ans = pmap[i][j];
                cout << pmap[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

	for(int i = 0; i < 4; i++)
    {
        int nmap[21][21];
        memset(nmap, 0, sizeof(nmap));
        memcpy(nmap, pmap, sizeof(nmap));


		//4방향에 대해 한 줄씩 배열로 만들어서
		//복사 - 이동 - 덮어쓰기
		int arr[21];
		
		int x = 0;
		int y = 0;
		int start = 0;
        int dt = 1;
        if(i == 0 || i == 3)
        {
            start = 0;
            dt = 1;
        }
        else if(i == 1 || i == 2)
        {
            start = n-1;
            dt = -1;
        }

		for(int j = start; (j < n && j>= 0); j+=dt)
        {
            int idx = 0;
			int cur = 0;
            for(int k = start; (k < n && k >= 0); k+=dt)
            {
                if(nmap[j][k] == 0) continue;
				if(i == 0 || i == 2) 
                {
                    x = j;
                    y = k;
                }
                else if (i == 1 || i == 3)
                {
                    x = k;
                    y = j;
                }
				arr[idx] = nmap[x][y];
				idx++;
			}
			idx = 1;
			
		}
		
		func(nmap, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int map[21][21];
	memset(map, 0, sizeof(map));

	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> map[i][j];
	
	int nmap[21][21];
	memcpy(nmap, map, sizeof(nmap));

	func(nmap ,0);

	return 0;
}